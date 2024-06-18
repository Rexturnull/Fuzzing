// gcc -o test test.c
#include <unistd.h>

int main()
{
    char input[8] = {0};
    read(STDIN_FILENO, input, 8);
    if (input[0] == 'A' && input[1] == 'B') // (1)
        *((unsigned int *)0) = 0xdeadbeef; // (2)
    write(STDOUT_FILENO, input, 8);
    return 0;
}