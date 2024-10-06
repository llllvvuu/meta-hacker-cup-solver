# Hacker Cup 2024

## Roadmap
- [x] Basic fixed two-shot prompt
- [ ] Improved scaffolding
- [ ] In-context examples selected by tagging problems
- [ ] Multi-turn and execution feedback
- [ ] Reflection, debate, etc
- [ ] STaR-style fine-tuning

## Round 1 Logs

Only a basic two-shot single-turn prompt was implemented for this round. I used Qwen 2.5 14B, which I did not realize at the time is against the rules (and unfortunately, I have not been able to get any results with eligible models). In addition, I did not upload to the website in time.

During the round, I ran pass@64 with a random seed, and a correct solution for A was generated (confirmed by doing a practice submission afterwards).

After putting a deterministic seed, I ran my pipeline again at pass@96 (~16 minutes) with some bugfixes, which generated correct solutions for A (13 points) and B (18 points).

The correct solution being selected for B is a fluke, as the tiebreaker is alphabetical.

Just for fun, I also did a pass@256 run, which exceeds the 20-minute time limit (it takes ~35 minutes). With this many samples, the majority voting starts to do its job and the correct solution for B is unambiguously selected.

To see the selected solutions, check: `round1_logs/pass@96/voted.txt` and `round1_logs/pass@256/voted.txt`. Also, see `round1_logs/pass@256/*.txt` for the model's output logs.

## Usage
Requires Python 3.12 or later.
Only tested on 40GB A100 with >80GB of RAM and CUDA 12.1.
```sh
pip install -r requirements.txt  # just vLLM
python pipeline.py contestData/ output/
python sample_grader.py output/ pass.txt fail.txt
python vote.py "contestData/$PROBLEM_NAME/full_in.txt" pass.txt "$PROBLEM_NAME" output.txt
```
