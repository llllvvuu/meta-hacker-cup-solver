import argparse
from pathlib import Path
import subprocess
import random
import math


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


def run_cpp_solution(exe_file: Path, input_file: Path) -> str:
    try:
        result = subprocess.run(
            exe_file,
            input=input_file.read_text(),
            capture_output=True,
            text=True,
            check=True,
            timeout=30,
        )
        return result.stdout.strip()
    except subprocess.TimeoutExpired:
        return "TIMEOUT"
    except Exception:
        return "ERROR"


def vote_on_solutions(
    full_input: Path, pass_file: Path, problem_name: str
) -> tuple[str, Path, list[tuple[str, list[Path]]]]:
    passing_solutions = [
        Path(line.strip())
        for line in pass_file.read_text().splitlines()
        if problem_name in line
    ]

    if not passing_solutions:
        raise ValueError(f"No passing solutions found for problem: {problem_name}")

    outputs: dict[Path, str] = {}
    for cpp_file in passing_solutions:
        exe_file = cpp_file.with_suffix(".exe")
        output = run_cpp_solution(exe_file, full_input)
        if output not in ["TIMEOUT", "ERROR"]:
            outputs[cpp_file] = output

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

    clusters.sort(key=len, reverse=True)

    winning_cluster = clusters[0]
    winning_cpp = random.choice(winning_cluster)
    winning_output = outputs[winning_cpp]

    sorted_groups = [(outputs[cluster[0]], cluster) for cluster in clusters]

    return winning_output, winning_cpp, sorted_groups


def main(args) -> None:
    full_input = Path(args.full_input)
    pass_file = Path(args.pass_file)
    problem_name = str(args.problem_name)
    voted_output = Path(args.voted_output)

    try:
        winning_output, winning_cpp, groups = vote_on_solutions(
            full_input, pass_file, problem_name
        )

        # Print out the agreeing groups
        for i, (_, cpp_files) in enumerate(groups, 1):
            cpp_names = ", ".join(cpp.name for cpp in cpp_files)
            print(f"Group {i}: {cpp_names}")

        print(f"\nWinner: {winning_cpp.name}")

        _ = voted_output.write_text(winning_output)
        print(f"Output written to: {voted_output}")
    except ValueError as e:
        print(f"Error: {e}")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Vote on C++ solutions for programming contest problems."
    )
    _ = parser.add_argument("full_input", type=str, help="Path to the full input file")
    _ = parser.add_argument(
        "pass_file", type=str, help="Path to the file containing passing solution paths"
    )
    _ = parser.add_argument(
        "problem_name", type=str, help="Name of the problem to vote on"
    )
    _ = parser.add_argument(
        "voted_output", type=str, help="Path to write the voted output"
    )

    args = parser.parse_args()
    main(args)
