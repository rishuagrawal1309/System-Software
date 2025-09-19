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
#include <unistd.h>

int main() {
    char *program = "./a.out";       
    char *arg1 = "John";             
    char *argv[] = {program, arg1, NULL};

    printf("Executing %s with argument: %s\n", program, arg1);

    execvp(program, argv);
    perror("execvp failed");
    return 1;
}

/*
============================================================================
Executing ./a.out with argument: John
argv[0] = ./a.out
argv[1] = John

============================================================================
*/