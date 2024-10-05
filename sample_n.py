import sys
from vllm import LLM, SamplingParams

n = int(sys.argv[1]) if len(sys.argv) > 1 else 32
model = sys.argv[2] if len(sys.argv) > 2 else "Qwen/Qwen2.5-14B"
prompts = [sys.stdin.read()]
sampling_params = SamplingParams(max_tokens=2048, n=n, stop="</problem>")
llm = LLM(model=model, max_model_len=8192, swap_space=32)
outputs = llm.generate(prompts, sampling_params)
for output in outputs:
    prompt = output.prompt
    for o in output.outputs:
        generated_text = o.text
        print(f"Prompt: {prompt}, Generated text: {generated_text}")
