/*
============================================================================
Name : que4.c
Author : Rishu agrawal
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 6 sept, 2025.
============================================================================
*/
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>
int main()
{
const char *exist_file= "f.txt";
const char *new_file="f2.txt";
int fd = open(exist_file, O_RDWR);
if(fd == -1)
{
perror("open f.txt");
}
else{
printf("opened file '%s' with fd %d\n",exist_file,fd);
close(fd);
}
int fd1 = open(exist_file, O_RDWR | O_EXCL);
if(fd1 == -1){
fprintf(stderr, "open with O_EXCL fail %s\n", strerror(errno));
}
else{
printf("opened with '%s' with O_EXCL %d\n", exist_file, fd1);
close(fd1);
}
return 0;
}
/*
============================================================================
opened file 'f.txt' with fd 3
opened with 'f.txt' with O_EXCL 4

============================================================================
*/
