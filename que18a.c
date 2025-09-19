/*
============================================================================
Name : que18a.c
Author : Rishu agrawal
Description : Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date: 6 sept, 2025.
============================================================================
*/

// init_records.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

struct record {
    int id;
    char name[20];
};

int main() {
    struct record recs[3] = {
        {1, "Alice"},
        {2, "Bob"},
        {3, "Charlie"}
    };

    int fd = open("records.dat", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd < 0) {
        perror("Error creating file");
        return 1;
    }

    if (write(fd, recs, sizeof(recs)) != sizeof(recs)) {
        perror("Error writing records");
        close(fd);
        return 1;
    }

    printf("Initialized file with 3 records.\n");
    close(fd);
    return 0;
}
/*
============================================================================
00000000  01 00 00 00 41 6c 69 63  65 00 00 00 00 00 00 00  |....A...........|
00000010  00 00 00 00 00 00 00 00  02 00 00 00 42 6f 62 00  |............B...|
00000020  00 00 00 00 00 00 00 00  00 00 00 00 00 00 03 00  |................|
00000030  00 00 43 68 61 72 6c 69  65 00 00 00 00 00 00 00  |..C.............|
...

============================================================================
*/
