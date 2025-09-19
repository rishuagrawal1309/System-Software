/*
============================================================================
Name : que23.c
Author : Rishu agrawal
Description : Write a program to create a Zombie state of the running program.
Date: 6 sept, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        printf("Child process exiting.\n");
        exit(0);  // Child exits immediately
    } else {
        printf("Parent process sleeping, child PID = %d\n", pid);
        printf("Check the process table now (e.g. with 'ps -l') to see the zombie.\n");
        sleep(30);  
        wait(NULL);
        printf("Parent collected the child. Zombie is gone.\n");
    }

    return 0;
}
/*
============================================================================
F S   UID   PID  PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
0 Z  1000  2345  2344  0  80   0 -     0 exit   pts/0    0:00  child process <defunct>

============================================================================
*/
