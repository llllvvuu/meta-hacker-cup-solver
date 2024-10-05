import argparse

from templates import TWO_SHOT_OBSERVATIONS_FIXED


def interpolate_sample_in_out(statement: str, sample_in: str, sample_out: str) -> str:
    lines = statement.split("\n")

    sample_explanation_index = next(
        (i for i, line in enumerate(lines) if line.strip() == "# Sample Explanation"),
        -1,
    )

    sample_input_section = "# Sample Input\n\n" + sample_in.strip() + "\n"
    sample_output_section = "# Sample Output\n\n" + sample_out.strip() + "\n"

    if sample_explanation_index != -1:
        lines.insert(sample_explanation_index, sample_output_section)
        lines.insert(sample_explanation_index, sample_input_section)
    else:
        lines.append(sample_input_section)
        lines.append(sample_output_section)

    return "\n".join(lines)


def basic_prompt(
    few_shot_examples: str,
    statement: str,
    sample_in: str,
    sample_out: str,
) -> str:
    return f"""{few_shot_examples}
<problem>
{interpolate_sample_in_out(statement, sample_in, sample_out)}
# Solution

<tags>
"""


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Generate a prompt using basic_prompt function"
    )
    _ = parser.add_argument("statement_file", help="Path to the statement file")
    _ = parser.add_argument("sample_input_file", help="Path to the sample input file")
    _ = parser.add_argument("sample_output_file", help="Path to the sample output file")

    args = parser.parse_args()

    with open(args.statement_file, "r") as f:
        statement = f.read()

    with open(args.sample_input_file, "r") as f:
        sample_input = f.read()

    with open(args.sample_output_file, "r") as f:
        sample_output = f.read()

    prompt = basic_prompt(TWO_SHOT_OBSERVATIONS_FIXED, statement, sample_input, sample_output)

    print(prompt)
