import sys
from vllm import LLM, SamplingParams

n = int(sys.argv[1]) if len(sys.argv) > 1 else 32
model = sys.argv[2] if len(sys.argv) > 2 else "Qwen/Qwen2.5-14B"
prompts = [sys.stdin.read()]
sampling_params = SamplingParams(max_tokens=1024, n=n)
llm = LLM(model=model, max_model_len=8192, swap_space=32)
outputs = llm.generate(prompts, sampling_params)
for output in outputs:
    prompt = output.prompt
    generated_text = output.outputs[0].text
    print(f"Prompt: {prompt}, Generated text: {generated_text}")
