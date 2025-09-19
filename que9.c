/*
============================================================================
Name : que9.c
Author : Rishu agrawal
Description : Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
Date: 6 sept, 2025.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<time.h>
int main()
{
int fd;
struct stat s;
fd = open("f1.txt",O_RDONLY);
if(fd<0)
{
perror("file open failed");
return 1;
}
if(fstat(fd, &s)==0)
{
printf("inode num %lu\n",(unsigned long)s.st_ino);
printf("no. of hardlinks %lu\n", (unsigned long)s.st_nlink);
printf("uid %d\n", s.st_uid);
printf("gid %d\n", s.st_gid);
printf("file size %ld bytes\n",(long)s.st_size);
printf("block size %ld bytes\n",(long)s.st_blksize);
printf("last access time %s\n", ctime(&s.st_atime));
printf("last modification time %s\n", ctime(&s.st_mtime));
}
else
{
perror("fstat failed");
close(fd);
return 1;
}
close(fd);
return 0;
}
/*
============================================================================
inode num 131242
no. of hardlinks 1
uid 1000
gid 1000
file size 6 bytes
block size 4096 bytes
last access time Sat Sep  6 11:10:15 2025
last modification time Sat Sep  6 11:05:33 2025
============================================================================
*/