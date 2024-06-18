#include<stdio.h>
#include<stdlib.h>


void backdoor(){
    system("sh");
}

int main(){

    setvbuf(stdout,0,2,0);
    setvbuf(stdin,0,2,0);
    setvbuf(stderr,0,2,0);

    puts( "Welcome to WORKSHOP<3." );

    char buf[0x30];
    gets( buf );

    return 0;
}