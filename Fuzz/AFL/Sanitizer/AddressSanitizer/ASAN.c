void *a;
char magic;
long unsigned shadow_mem_addr;

a = (void *)0x87870000;
shadow_mem_addr = (long unsigned)a >> 3; // (1)
shadow_mem_addr += 0x7fff8000; // (2)
magic = *(char *)shadow_mem_addr;

if (magic < 0) // (3)
    dump_and_abort();

if (((long unsigned)a & 7) > magic) // (4)
    dump_and_abort();