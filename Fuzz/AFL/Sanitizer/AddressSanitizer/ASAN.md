ASAN
===

# Shadow Memory
存取速度的優化
```C
void *a;
char magic;
long unsigned shadow_mem_addr;

// 記憶體位址為 0x87870000，首先會對位址右移三個 3 bits
a = (void *)0x87870000;
shadow_mem_addr = (long unsigned)a >> 3;
// 加上一個固定的 offset 得到的記憶體位址即是 shadow memory
shadow_mem_addr += 0x7fff8000; // (2)
magic = *(char *)shadow_mem_addr;


// 而 < 0 的值代表漏洞發生，並且不同的值代表不同的意義
// 舉例來說發生 Freed heap region (UAF) 漏洞時
// 值就會是 FD
if (magic < 0) // (3)
    dump_and_abort();


// shadow memory 裡面存放的值即是要存取的記憶體的型態
// 如果值為 00 的話就是正常的範圍
// 01~07 代表記憶體本來就不對齊
// 因此還要考慮到記憶體被存取時的偏移
if (((long unsigned)a & 7) > magic) // (4)
    dump_and_abort();
```
