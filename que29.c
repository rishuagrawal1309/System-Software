/*
============================================================================
Name : que29.c
Author : Rishu agrawal
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
Date: 6 sept, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

const char* policy_to_str(int policy) {
    switch (policy) {
        case SCHED_OTHER: return "SCHED_OTHER (default)";
        case SCHED_FIFO:  return "SCHED_FIFO (real-time FIFO)";
        case SCHED_RR:    return "SCHED_RR (real-time Round Robin)";
        case SCHED_BATCH: return "SCHED_BATCH";
        case SCHED_IDLE:  return "SCHED_IDLE";
        default:          return "UNKNOWN";
    }
}

int main(int argc, char *argv[]) {
    int policy;
    struct sched_param param;
    pid_t pid = 0; 
    policy = sched_getscheduler(pid);
    if (policy == -1) {
        perror("sched_getscheduler");
        return 1;
    }

    printf("Current scheduling policy: %s\n", policy_to_str(policy));

    if (sched_getparam(pid, &param) == -1) {
        perror("sched_getparam");
        return 1;
    }
    printf("Current priority: %d\n", param.sched_priority);

    if (argc < 3) {
        printf("Usage: %s <policy> <priority>\n", argv[0]);
        printf("Policies: fifo, rr, other\n");
        return 1;
    }

    int new_policy;
    if (strcmp(argv[1], "fifo") == 0) {
        new_policy = SCHED_FIFO;
    } else if (strcmp(argv[1], "rr") == 0) {
        new_policy = SCHED_RR;
    } else if (strcmp(argv[1], "other") == 0) {
        new_policy = SCHED_OTHER;
    } else {
        fprintf(stderr, "Unknown policy '%s'\n", argv[1]);
        return 1;
    }

    int new_priority = atoi(argv[2]);
    int min_priority = sched_get_priority_min(new_policy);
    int max_priority = sched_get_priority_max(new_policy);

    if (new_priority < min_priority || new_priority > max_priority) {
        fprintf(stderr, "Priority must be between %d and %d for policy %s\n",
                min_priority, max_priority, argv[1]);
        return 1;
    }

    param.sched_priority = new_priority;

    if (sched_setscheduler(pid, new_policy, &param) == -1) {
        perror("sched_setscheduler");
        return 1;
    }

    printf("Changed scheduling policy to %s with priority %d\n", policy_to_str(new_policy), new_priority);
    policy = sched_getscheduler(pid);
    sched_getparam(pid, &param);
    printf("New scheduling policy: %s\n", policy_to_str(policy));
    printf("New priority: %d\n", param.sched_priority);

    return 0;
}

/*
============================================================================
Current scheduling policy: SCHED_OTHER (default)
Current priority: 0
Changed scheduling policy to SCHED_FIFO (real-time FIFO) with priority 50
New scheduling policy: SCHED_FIFO (real-time FIFO)
New priority: 50
============================================================================
*/