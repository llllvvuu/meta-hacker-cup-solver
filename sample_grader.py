import subprocess
import argparse
from pathlib import Path
import math
from concurrent.futures import ThreadPoolExecutor, as_completed
import os


def is_close(a: str, b: str, rel_tol: float = 1e-6, abs_tol: float = 1e-6) -> bool:
    try:
        float_a, float_b = float(a), float(b)
        return math.isclose(float_a, float_b, rel_tol=rel_tol, abs_tol=abs_tol)
    except ValueError:
        return a == b


def compare_outputs(expected_output: str, actual_output: str) -> bool:
    expected_words = expected_output.split()
    actual_words = actual_output.split()

    if len(expected_words) != len(actual_words):
        return False

    for expected_word, actual_word in zip(expected_words, actual_words):
        if "." in expected_word or "." in actual_word:
            if not is_close(expected_word, actual_word):
                return False
        elif expected_word != actual_word:
            return False

    return True


def compile_and_test_cpp_file(
    cpp_file: Path, contest_data_dir: str
) -> tuple[Path, str]:
    exe_file = cpp_file.with_suffix(".exe")
    compile_command = f'g++ -std=c++17 -O2 "{cpp_file}" -o "{exe_file}"'
    try:
        _ = subprocess.run(
            compile_command, shell=True, check=True, stderr=subprocess.DEVNULL
        )
    except subprocess.CalledProcessError:
        return cpp_file, "ERR"

    problem_name = cpp_file.stem.rsplit("_", 1)[0]
    input_file = Path(contest_data_dir) / problem_name / "sample_in.txt"
    expected_output_file = Path(contest_data_dir) / problem_name / "sample_out.txt"
    actual_output_file = exe_file.with_name(f"{exe_file.stem}.sample_out")

    try:
        with open(input_file, "r") as infile, open(actual_output_file, "w") as outfile:
            _ = subprocess.run(
                f'"{exe_file}"',
                stdin=infile,
                stdout=outfile,
                shell=True,
                check=True,
                timeout=5,
            )

        with open(expected_output_file, "r") as f:
            expected_output = f.read()
        with open(actual_output_file, "r") as f:
            actual_output = f.read()

        result = "PASS" if compare_outputs(expected_output, actual_output) else "FAIL"
    except subprocess.TimeoutExpired:
        result = "TIME"
    except Exception:
        result = "ERR"

    return cpp_file, result


def process_cpp_files(
    output_dir: str,
    contest_data_dir: str,
    pass_file: Path,
    fail_file: Path,
    num_threads: int,
) -> None:
    cpp_files = list(Path(output_dir).glob("*.cpp"))
    max_filename_length = max(len(str(cpp_file)) for cpp_file in cpp_files)
    passing_files: list[str] = []
    failing_files: list[str] = []

    def process_result(future):
        cpp_file, result = future.result()
        print(
            f"{cpp_file} {'.' * (max_filename_length - len(str(cpp_file)) + 3)} {result}"
        )
        if result == "PASS":
            passing_files.append(str(cpp_file))
        elif result == "FAIL":
            failing_files.append(str(cpp_file))

    with ThreadPoolExecutor(max_workers=num_threads) as executor:
        futures = [
            executor.submit(compile_and_test_cpp_file, cpp_file, contest_data_dir)
            for cpp_file in cpp_files
        ]
        for future in as_completed(futures):
            process_result(future)

    with open(pass_file, "w") as f:
        _ = f.write("\n".join(passing_files))

    with open(fail_file, "w") as f:
        _ = f.write("\n".join(failing_files))


def main(args) -> None:
    output_dir: str = args.output_dir
    contest_data_dir: str | Path = (
        args.contest_data_dir or Path(output_dir).parent / "contestData"
    )
    pass_file: Path = Path(args.pass_file)
    fail_file: Path = Path(args.fail_file)
    num_threads: int = args.jobs if args.jobs > 0 else os.cpu_count() or 1

    print(f"Compiling, running, and grading C++ files using {num_threads} threads...")
    process_cpp_files(output_dir, contest_data_dir, pass_file, fail_file, num_threads)
    print(f"\nPassing file paths have been written to {pass_file}")
    print(f"Failing file paths have been written to {fail_file}")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Grade generated C++ solutions for programming contest problems."
    )
    _ = parser.add_argument(
        "output_dir", type=str, help="Directory containing the generated .cpp files"
    )
    _ = parser.add_argument(
        "pass_file", type=str, help="File to write paths of passing .cpp files"
    )
    _ = parser.add_argument(
        "fail_file", type=str, help="File to write paths of failing .cpp files"
    )
    _ = parser.add_argument(
        "--contest_data_dir",
        type=str,
        help="Directory containing the contest data (default: ../contestData relative to output_dir)",
    )
    _ = parser.add_argument(
        "-j",
        "--jobs",
        type=int,
        default=0,
        help="Number of parallel jobs to run (default: number of CPUs)",
    )

    args = parser.parse_args()

    main(args)
