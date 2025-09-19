/*
============================================================================
Name : que3.c
Author : Rishu agrawal
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 6 sept, 2025.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
const char *filename = "f.txt";
int fd = creat(filename, 0600);
if(fd==-1){
perror("create");
return 1;
}
printf("file '%s' created with file descriptor %d\n", filename,fd);
close(fd);
return 0;
}
/*
============================================================================
file 'f.txt' created with file descriptor 3
============================================================================
*/