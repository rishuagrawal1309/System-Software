/*
============================================================================
Name : que18b.c
Author : Rishu agrawal
Description : Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date: 6 sept, 2025.
============================================================================
*/

// record_lock.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

struct record {
    int id;
    char name[20];
};

void lock_record(int fd, int rec_num, short lock_type) {
    struct flock lock;
    off_t offset = rec_num * sizeof(struct record);

    lock.l_type = lock_type;
    lock.l_whence = SEEK_SET;
    lock.l_start = offset;
    lock.l_len = sizeof(struct record);

    printf("Trying to acquire %s lock on record %d...\n",
           (lock_type == F_RDLCK) ? "READ" : "WRITE", rec_num + 1);

    if (fcntl(fd, F_SETLKW, &lock) < 0) {
        perror("Error locking record");
        exit(1);
    }

    printf("%s lock acquired on record %d.\n",
           (lock_type == F_RDLCK) ? "Read" : "Write", rec_num + 1);
}

void unlock_record(int fd, int rec_num) {
    struct flock lock;
    off_t offset = rec_num * sizeof(struct record);

    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = offset;
    lock.l_len = sizeof(struct record);

    if (fcntl(fd, F_SETLK, &lock) < 0) {
        perror("Error unlocking record");
        exit(1);
    }

    printf("Lock released on record %d.\n", rec_num + 1);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <record_number 1-3> <r/w>\n", argv[0]);
        return 1;
    }

    int rec_num = atoi(argv[1]) - 1;
    char mode = argv[2][0];

    if (rec_num < 0 || rec_num > 2) {
        fprintf(stderr, "Record number must be between 1 and 3.\n");
        return 1;
    }

    int fd = open("records.dat", O_RDWR);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    struct record rec;

    if (mode == 'r') {
        lock_record(fd, rec_num, F_RDLCK);

        lseek(fd, rec_num * sizeof(struct record), SEEK_SET);
        read(fd, &rec, sizeof(rec));
        printf("Record %d: ID=%d, Name=%s\n", rec_num + 1, rec.id, rec.name);

        getchar(); 
        unlock_record(fd, rec_num);

    } else if (mode == 'w') {
        lock_record(fd, rec_num, F_WRLCK);

        lseek(fd, rec_num * sizeof(struct record), SEEK_SET);
        read(fd, &rec, sizeof(rec));

        printf("Current Record %d: ID=%d, Name=%s\n", rec_num + 1, rec.id, rec.name);

        printf("Enter new name: ");
        scanf("%s", rec.name);

        lseek(fd, rec_num * sizeof(struct record), SEEK_SET);
        write(fd, &rec, sizeof(rec));

        printf("Record updated.\n");

        getchar(); 
        getchar(); 
        unlock_record(fd, rec_num);

    } else {
        fprintf(stderr, "Invalid mode. Use 'r' or 'w'.\n");
    }

    close(fd);
    return 0;
}

/*
============================================================================
TERMINAL 1
./record_lock 2 r
Trying to acquire READ lock on record 2...
Read lock acquired on record 2.
Record 2: ID=2, Name=Bob
<waits for Enter>

TERMINAL 2
./record_lock 2 w
Trying to acquire WRITE lock on record 2...

Write lock acquired on record 2.
Current Record 2: ID=2, Name=Bob
Enter new name: Bobby
Record updated.

============================================================================
*/