/*
============================================================================
Name : que27c.c
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

extern char **environ;  

int main() {
    printf("Running ls -Rl using execle\n");

    execle("/bin/ls", "ls", "-Rl", (char *)NULL, environ);

    perror("execle failed");
    return 1;
}

/*
============================================================================
Running ls -Rl using execle
.:
file1.txt  file2.txt  subdir/

./subdir:
file3.txt

============================================================================
*/