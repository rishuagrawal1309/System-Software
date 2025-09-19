/*
============================================================================
Name : que24.c
Author : Rishu agrawal
Description : Write a program to create an orphan process.
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
        printf("Child process started. PID = %d, Parent PID = %d\n", getpid(), getppid());
        sleep(10);
        printf("Child process after parent exit. PID = %d, New Parent PID = %d\n", getpid(), getppid());
    } else {  
        printf("Parent process exiting. PID = %d\n", getpid());
        exit(0); 
     }   

    return 0;
}
/*
============================================================================
Parent process exiting. PID = 2342
Child process started. PID = 2345, Parent PID = 2342
Child process after parent exit. PID = 2345, New Parent PID = 1

============================================================================
*/
