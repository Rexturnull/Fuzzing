pass
===

# Compile
```bash
# 不開PIE和Stack Canary
gcc test.c -fno-stack-protector -no-pie -o test
```

# Fuzz
Fuzz Test
```bash
# compile
afl-gcc test.c -fno-stack-protector -no-pie -o test

# generate seed
mkdir in && echo 'seed' > in/seed
# 這邊提供的seed是"seed"字串
# 也可以提供很多個
# 只要放在in資料夾即可

# Execute fuzzer
afl-fuzz -i in -o out ./test
# 輸出到out資料夾
```