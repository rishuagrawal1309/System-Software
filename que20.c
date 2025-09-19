/*
============================================================================
Name : que20.c
Author : Rishu agrawal
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 6 sept, 2025.
============================================================================
*/
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    
    int nice_value = getpriority(PRIO_PROCESS, 0);
    if (nice_value == -1) {
        perror("getpriority");
        return 1;
    }
    printf("Current nice value: %d\n", nice_value);
    return 0;
}

/*
============================================================================
Current nice value: 0

============================================================================
*/