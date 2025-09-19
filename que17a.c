/*
============================================================================
Name : que17a.c
Author : Rishu agrawal
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 6 sept, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("ticket.txt", "w");
    if (fp == NULL) {
        perror("Error creating ticket file");
        return 1;
    }

    int ticket_no = 100;
    fprintf(fp, "%d\n", ticket_no);
    fclose(fp);

    printf("Ticket file initialized with ticket number %d\n", ticket_no);
    return 0;
}
/*
============================================================================
Ticket file initialized with ticket number 100

============================================================================
*/
