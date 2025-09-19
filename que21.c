/*
============================================================================
Name : que21.c
Author : Rishu agrawal
Description : Write a program, call fork and print the parent and child process id.
Date: 6 sept, 2025.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }
    else if (pid == 0) {
        printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
    }
    else {
        printf("Parent Process: PID = %d, Child PID = %d\n", getpid(), pid);
    }

    return 0;
}

/*
============================================================================
Parent Process: PID = 1234, Child PID = 1235
Child Process: PID = 1235, Parent PID = 1234

============================================================================
*/