/*
============================================================================
Name : que15.c
Author : Rishu agrawal
Description : Write a program to display the environmental variable of the user (use environ).
Date: 6 sept, 2025.
============================================================================
*/
#include <stdio.h>
extern char **environ;

int main() {
    char **env = environ;

    printf("Environment Variables:\n\n");

    while (*env) {
        printf("%s\n", *env);
        env++;
    }

    return 0;
}
/*
============================================================================
Environment Variables:

USER=rishu
HOME=/home/rishu
PATH=/usr/local/bin:/usr/bin:/bin
SHELL=/bin/bash
...

============================================================================
*/
