test-1
===

```
Simple Fuzzer by python
```

# Fuzz
```bash
import subprocess

target = './test'
inps = ['AA', 'BB', 'BA', 'AB']

for inp in inps:
    try:
        subprocess.run([target], input=inp.encode(), capture_output=True, check=True)
    except subprocess.CalledProcessError: # (1)
        print(f"bug found with input: '{inp}'")

# (output)
# bug found with input: 'AB'
```