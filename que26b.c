/*
============================================================================
Name : que26.c
Author : Rishu agrawal
Description : Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 6 sept, 2025.
============================================================================
*/
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s name\n", argv[0]);
        return 1;
    }
    printf("Hello, %s!\n", argv[1]);
    return 0;
}
/*
============================================================================
Hello, John!
============================================================================
*/
