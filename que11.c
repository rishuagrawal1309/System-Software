/*
============================================================================
Name : que11.c
Author : Rishu agrawal
Description :Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
Date: 6 sept, 2025.
============================================================================
*/
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main()
{
const char *filename= "ff.txt";
int fd = open(filename,O_WRONLY|O_CREAT|O_APPEND, 0644);
if(fd<0){
perror("open");
return EXIT_FAILURE;
}
int new_fd = dup(fd);
if(new_fd<0){
perror("dup");
close(fd);
return EXIT_FAILURE;
}
int fd2= dup2(fd ,10);
if(fd2 <0)
{
perror("dup2");
close(fd);
close(new_fd);
return EXIT_FAILURE;
}
int fd_fcntl = fcntl(fd , F_DUPFD,20);
if(fd_fcntl<0){
perror("fcntl");
close(fd);
close(new_fd);
close(fd2);
return EXIT_FAILURE;
}
return 0;
}
/*
============================================================================
fd      = 3
new_fd  = 4
fd2     = 10
fd_fcntl= 20

============================================================================
*/