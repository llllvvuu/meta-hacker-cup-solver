import argparse
from pathlib import Path
import subprocess
import random
import math
from concurrent.futures import ThreadPoolExecutor, as_completed
import os
import time
import shutil


def is_close(a: str, b: str, rel_tol: float = 1e-6, abs_tol: float = 1e-6) -> bool:
    try:
        float_a, float_b = float(a), float(b)
        return math.isclose(float_a, float_b, rel_tol=rel_tol, abs_tol=abs_tol)
    except ValueError:
        return a == b


def compare_outputs(output1: str, output2: str) -> bool:
    words1 = output1.split()
    words2 = output2.split()

    if len(words1) != len(words2):
        return False

    for w1, w2 in zip(words1, words2):
        if "." in w1 or "." in w2:
            if not is_close(w1, w2):
                return False
        elif w1 != w2:
            return False

    return True


def run_cpp_solution(exe_file: Path, input_file: Path) -> tuple[Path, str]:
    try:
        result = subprocess.run(
            exe_file,
            input=input_file.read_text(),
            capture_output=True,
            text=True,
            check=True,
            timeout=30,
        )
        return exe_file, result.stdout.strip()
    except subprocess.TimeoutExpired:
        return exe_file, "TIMEOUT"
    except Exception as e:
        print(e)
        return exe_file, "ERROR"


def vote_on_solutions(
    full_input: Path, passing_solutions: list[Path], num_threads: int
) -> tuple[str, Path, list[tuple[str, list[Path]]]]:
    outputs: dict[Path, str] = {}
    total_solutions = len(passing_solutions)

    print(f"Running {total_solutions} solutions")
    start_time = time.time()

    with ThreadPoolExecutor(max_workers=num_threads) as executor:
        future_to_cpp = {
            executor.submit(
                run_cpp_solution, cpp_file.with_suffix(".exe"), full_input
            ): cpp_file
            for cpp_file in passing_solutions
        }
        for i, future in enumerate(as_completed(future_to_cpp), 1):
            cpp_file = future_to_cpp[future]
            exe_file, output = future.result()
            if output not in ["TIMEOUT", "ERROR"]:
                outputs[cpp_file] = output

            elapsed_time = time.time() - start_time
            print(
                f"\rProgress: {i}/{total_solutions} solutions processed. Elapsed time: {elapsed_time:.2f}s",
                end="",
                flush=True,
            )

    print("\nAll solutions processed.")

    if not outputs:
        raise ValueError("All solutions resulted in timeout or error")

    clusters: list[list[Path]] = []
    for cpp, output in outputs.items():
        for cluster in clusters:
            if compare_outputs(output, outputs[cluster[0]]):
                cluster.append(cpp)
                break
        else:
            clusters.append([cpp])

    clusters.sort(key=lambda x: (-len(x), x[0].name))

    winning_cluster = clusters[0]
    winning_cpp = winning_cluster[0]
    winning_output = outputs[winning_cpp]

    sorted_groups = [
        (outputs[cluster[0]], sorted(cluster, key=lambda x: x.name))
        for cluster in clusters
    ]

    return winning_output, winning_cpp, sorted_groups


def process_problem(
    problem_name: str,
    contest_data_dir: Path,
    passing_solutions: list[Path],
    voted_output_dir: Path,
    num_threads: int,
) -> None:
    full_input = contest_data_dir / problem_name / "full_in.txt"

    print(f"\nProcessing problem: {problem_name}")

    try:
        winning_output, winning_cpp, groups = vote_on_solutions(
            full_input, passing_solutions, num_threads
        )

        print("\nVoting results:")
        for i, (_, cpp_files) in enumerate(groups, 1):
            cpp_names = ", ".join(cpp.name for cpp in cpp_files)
            print(f"Group {i}: {cpp_names}")

        print(f"\nWinner: {winning_cpp.name}")

        # Write output file
        output_file = voted_output_dir / f"{problem_name}.out"
        output_file.write_text(winning_output)
        print(f"Output written to: {output_file}")

        # Copy winning cpp file
        dest_cpp_file = voted_output_dir / f"{problem_name}.cpp"
        shutil.copy2(winning_cpp, dest_cpp_file)
        print(f"Winning cpp file copied to: {dest_cpp_file}")

    except ValueError as e:
        print(f"Error processing {problem_name}: {e}")


def main(args) -> None:
    random.seed(42)
    contest_data_dir = Path(args.contest_data_dir)
    pass_file = Path(args.pass_file)
    voted_output_dir = Path(args.voted_output_dir)
    num_threads = args.jobs if args.jobs > 0 else os.cpu_count() or 1

    print(f"Using {num_threads} threads for parallel execution.")

    # Create voted_output_dir if it doesn't exist
    voted_output_dir.mkdir(parents=True, exist_ok=True)

    # Read pass_file and group solutions by problem
    problems = {}
    for line in pass_file.read_text().splitlines():
        path = Path(line.strip())
        problem_name = path.name.split("_")[0]
        if problem_name not in problems:
            problems[problem_name] = []
        problems[problem_name].append(path)

    # Process each problem
    for problem_name, passing_solutions in problems.items():
        process_problem(
            problem_name,
            contest_data_dir,
            passing_solutions,
            voted_output_dir,
            num_threads,
        )


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Vote on C++ solutions for multiple programming contest problems."
    )
    parser.add_argument(
        "contest_data_dir", type=str, help="Directory containing problem input files"
    )
    parser.add_argument(
        "pass_file", type=str, help="Path to the file containing passing solution paths"
    )
    parser.add_argument(
        "voted_output_dir",
        type=str,
        help="Directory to write the voted outputs and winning cpp files",
    )
    parser.add_argument(
        "-j",
        "--jobs",
        type=int,
        default=0,
        help="Number of parallel jobs to run (default: number of CPUs)",
    )

    args = parser.parse_args()
    main(args)
