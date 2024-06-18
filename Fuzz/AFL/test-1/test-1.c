#include <stdio.h>
#include <unistd.h>

int main()
{
    int a;
    read(0, &a, 0x2);
    if (a == 0xdead)
        *(int *)0 = 0xdeadbeef;
    return 0;
}