/*
============================================================================
Name : que27d.c
Author : Rishu agrawal
Description : Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execle
d. execv
e. execvp
Date: 6 sept, 2025.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main() {
    char *argv[] = {"ls", "-Rl", NULL};

    printf("Running ls -Rl using execv\n");

    execv("/bin/ls", argv);

    perror("execv failed");
    return 1;
}
/*
============================================================================
Running ls -Rl using execv
.:
file1.txt  file2.txt  subdir/

./subdir:
file3.txt

============================================================================
*/
