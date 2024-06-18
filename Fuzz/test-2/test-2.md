test
===

```
Simple Fuzzer by python
```

# Fuzzer
```python
import subprocess
import random

target = './test'
inps = ['A', 'B']
count = 1

while True:
    inp = inps[0] # (1)
    inp += random.choice(['A', 'B', 'C']) # (2)
    del inps[0]
    count += 1

    try:
        comp = subprocess.run([target], input=inp.encode(), capture_output=True, check=True)
        if comp.stdout != b'':
            inps.append(inp) # (3)
    except subprocess.CalledProcessError:
        print(f"bug found with input: '{inp}'")
        break

    if count % 100 == 0 or len(inps) == 0: # (4)
        inps = ['A', 'B']
```