/*
============================================================================
Name : que16.c
Author : Rishu agrawal
Description : Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock
Date: 6 sept, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

void set_lock(int fd, short type) {
    struct flock lock;

    lock.l_type = type;           
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;            
    lock.l_len = 0;              

    printf("Trying to set a %s lock...\n", (type == F_RDLCK) ? "READ" : "WRITE");

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Failed to set lock");
        exit(EXIT_FAILURE);
    }

    printf("%s lock acquired. Press Enter to release it...\n", (type == F_RDLCK) ? "Read" : "Write");
    getchar();

    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Failed to release lock");
        exit(EXIT_FAILURE);
    }

    printf("Lock released.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename> <r/w>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *filename = argv[1];
    char mode = argv[2][0];
    int fd;

   
    if (mode == 'r') {
        fd = open(filename, O_RDONLY);
    } else if (mode == 'w') {
        fd = open(filename, O_WRONLY);
    } else {
        fprintf(stderr, "Invalid mode. Use 'r' for read lock or 'w' for write lock.\n");
        exit(EXIT_FAILURE);
    }

    if (fd < 0) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    if (mode == 'r') {
set_lock(fd, F_RDLCK);
    } else {
        set_lock(fd, F_WRLCK);
    }

    close(fd);
    return 0;
}
/*
============================================================================
echo "Hello World" > myfile.txt
./a.out myfile.txt w
Trying to set a WRITE lock...
Write lock acquired. Press Enter to release it...

(RUN IN ANOTHER TERMINAL)
./a.out myfile.txt r

============================================================================
*/
