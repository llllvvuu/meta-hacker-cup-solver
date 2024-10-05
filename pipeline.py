import os
import re
import argparse
from prompts import basic_prompt
from templates import TWO_SHOT_OBSERVATIONS_FIXED


def get_problem_dirs(contest_data_dir: str) -> list[str]:
    return [
        d
        for d in os.listdir(contest_data_dir)
        if os.path.isdir(os.path.join(contest_data_dir, d))
    ]


def generate_prompts(
    contest_data_dir: str, problem_dirs: list[str]
) -> list[tuple[str, str]]:
    prompts: list[tuple[str, str]] = []
    for problem_dir in problem_dirs:
        full_problem_dir = os.path.join(contest_data_dir, problem_dir)
        with open(os.path.join(full_problem_dir, "statement.txt"), "r") as f:
            statement = f.read()
        with open(os.path.join(full_problem_dir, "sample_in.txt"), "r") as f:
            sample_input = f.read()
        with open(os.path.join(full_problem_dir, "sample_out.txt"), "r") as f:
            sample_output = f.read()

        prompt = basic_prompt(
            TWO_SHOT_OBSERVATIONS_FIXED, statement, sample_input, sample_output
        )
        prompts.append((problem_dir, prompt))
    return prompts


def sample_completions(
    prompts: list[tuple[str, str]], n: int, model: str, max_tokens: int
) -> dict[str, list[str]]:
    from vllm import LLM, SamplingParams
    sampling_params = SamplingParams(max_tokens=max_tokens, n=n, stop="</problem>")
    llm = LLM(model=model, max_model_len=8192, swap_space=32, gpu_memory_utilization=0.95)

    prompt_texts = [prompt for _, prompt in prompts]
    outputs = llm.generate(prompt_texts, sampling_params)

    completions: dict[str, list[str]] = {}
    for (problem_dir, _), output in zip(prompts, outputs):
        completions[problem_dir] = [o.text for o in output.outputs]

    return completions


def extract_cpp_code(completion: str) -> str | None:
    cpp_pattern = r"```cpp\n(.*?)```"
    match = re.search(cpp_pattern, completion, re.DOTALL)
    return match.group(1) if match else None


def save_results(completions: dict[str, list[str]], output_dir: str):
    os.makedirs(output_dir, exist_ok=True)

    for problem_name, problem_completions in completions.items():
        with open(os.path.join(output_dir, f"{problem_name}.txt"), "w") as f:
            for i, completion in enumerate(problem_completions, 1):
                _ = f.write(f"Completion {i}:\n")
                _ = f.write("=" * 80 + "\n")
                _ = f.write(completion + "\n\n")
        for i, completion in enumerate(problem_completions, 1):
            cpp_code = extract_cpp_code(completion)
            if cpp_code:
                with open(
                    os.path.join(output_dir, f"{problem_name}_{i}.cpp"), "w"
                ) as f:
                    _ = f.write(cpp_code)


def main(args) -> None:
    problem_dirs = get_problem_dirs(args.contest_data_dir)
    print(f"Found {len(problem_dirs)} problems")

    prompts = generate_prompts(args.contest_data_dir, problem_dirs)
    print("Generated prompts for all problems")

    completions = sample_completions(
        prompts, args.num_samples, args.model, args.max_tokens
    )
    print(f"Generated {args.num_samples} completions for each problem")

    save_results(completions, args.output_dir)
    print(f"Saved results to {args.output_dir}")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Generate completions for programming contest problems."
    )
    _ = parser.add_argument(
        "-n",
        "--num_samples",
        type=int,
        default=32,
        help="Number of completions to generate per problem",
    )
    _ = parser.add_argument(
        "-m",
        "--model",
        type=str,
        default="Qwen/Qwen2.5-14B",
        help="Model to use for generation",
    )
    _ = parser.add_argument(
        "-t",
        "--max_tokens",
        type=int,
        default=2048,
        help="Maximum number of tokens to generate per completion",
    )
    _ = parser.add_argument(
        "contest_data_dir", type=str, help="Directory containing the contest data"
    )
    _ = parser.add_argument("output_dir", type=str, help="Directory to save the output")

    args = parser.parse_args()

    main(args)
