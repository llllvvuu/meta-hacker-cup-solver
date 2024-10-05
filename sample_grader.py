import subprocess
import argparse
from pathlib import Path


def compile_and_test_cpp_file(cpp_file: Path, contest_data_dir: str) -> str:
    exe_file = cpp_file.with_suffix(".exe")
    compile_command = f'clang++ -O3 "{cpp_file}" -o "{exe_file}"'
    try:
        _ = subprocess.run(
            compile_command, shell=True, check=True, stderr=subprocess.DEVNULL
        )
    except subprocess.CalledProcessError:
        return "ERR"

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
        diff_result = subprocess.run(
            ["diff", expected_output_file, actual_output_file],
            capture_output=True,
            text=True,
        )
        return "PASS" if diff_result.returncode == 0 else "FAIL"
    except subprocess.TimeoutExpired:
        return "TIME"
    except Exception:
        return "ERR"


def process_cpp_files(output_dir: str, contest_data_dir: str) -> None:
    cpp_files = list(Path(output_dir).glob("*.cpp"))
    max_filename_length = max(len(str(cpp_file)) for cpp_file in cpp_files)

    for cpp_file in cpp_files:
        print(
            f"{cpp_file} {'.' * (max_filename_length - len(str(cpp_file)) + 3)}",
            end="",
            flush=True,
        )
        result = compile_and_test_cpp_file(cpp_file, contest_data_dir)
        print(f" {result}")


def main(args):
    output_dir: str = args.output_dir
    contest_data_dir: str | Path = (
        args.contest_data_dir or Path(output_dir).parent / "contestData"
    )

    print("Compiling, running, and grading C++ files...")
    process_cpp_files(output_dir, contest_data_dir)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Grade generated C++ solutions for programming contest problems."
    )
    _ = parser.add_argument(
        "output_dir", type=str, help="Directory containing the generated .cpp files"
    )
    _ = parser.add_argument(
        "--contest_data_dir",
        type=str,
        help="Directory containing the contest data (default: ../contestData relative to output_dir)",
    )

    args = parser.parse_args()

    main(args)
