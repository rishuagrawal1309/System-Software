/*
============================================================================
Name : que27b.c
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
    printf("Running ls -Rl using execlp\n");

    execlp("ls", "ls", "-Rl", (char *)NULL);

    perror("execlp failed");
    return 1;
}
/*
============================================================================
Running ls -Rl using execlp
.:
file1.txt  file2.txt  subdir/

./subdir:
file3.txt

============================================================================
*/
