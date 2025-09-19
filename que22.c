/*
============================================================================
Name : que22.c
Author : Rishu agrawal
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 6 sept, 2025.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        close(fd);
        return 1;
    }
    else if (pid == 0) {
        const char *child_msg = "Child process writing.\n";
        write(fd, child_msg, strlen(child_msg));
        close(fd);
        _exit(0);  
    }
    else {
        const char *parent_msg = "Parent process writing.\n";
        write(fd, parent_msg, strlen(parent_msg));   
        wait(NULL);
        close(fd);
    }

    printf("Both parent and child have written to the file.\n");
    return 0;
}
/*
============================================================================
Parent process writing.
Child process writing.

============================================================================
*/
