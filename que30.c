/*
============================================================================
Name : que30.c
Author : Rishu agrawal
Description : Write a program to run a script at a specific time using a Daemon process.
Date: 6 sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define SCRIPT_PATH "/path/to/your/script.sh"
#define TARGET_HOUR 14  
#define TARGET_MIN 30   

void daemonize() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    if (pid > 0) {
       
        exit(EXIT_SUCCESS);
    }
    if (setsid() < 0) {
        perror("setsid failed");
        exit(EXIT_FAILURE);
    }

  
    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

  
    umask(0);

    
    if (chdir("/") < 0) {
        perror("chdir failed");
        exit(EXIT_FAILURE);
    }

   
    for (int fd = sysconf(_SC_OPEN_MAX); fd >= 0; fd--) {
        close(fd);
    }

    open("/dev/null", O_RDWR); 
    dup(0);                 
    dup(0);                
}

int main() {
    daemonize();

    while (1) {
        time_t now = time(NULL);
        struct tm *local = localtime(&now);

        if (local->tm_hour == TARGET_HOUR && local->tm_min == TARGET_MIN && local->tm_sec == 0) {
            system(SCRIPT_PATH);

            sleep(61);
        } else {
            
            sleep(1);
        }
    }

    return 0;
}

/*
============================================================================
Script executed!

============================================================================
*/