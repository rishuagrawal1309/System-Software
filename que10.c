/*
============================================================================
Name : que10.c
Author : Rishu agrawal
Description :Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
Date: 6 sept, 2025.
============================================================================
*/
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
int main()
{
const char *filename = "ff.txt";
int fd = open(filename, O_RDWR|O_CREAT, 0644);
if(fd == -1)
{
perror("open");
return EXIT_FAILURE;
}
off_t offset = lseek(fd,10,SEEK_CUR);
if(offset==-1)
{
perror("lseek");
close(fd);
return EXIT_FAILURE;
}
else{
printf("lseek success. Offset: %ld\n",offset);
}
const char *data= "RRRRRRRRRR";
if(write(fd,data,10)!=10){
perror("write data");
close(fd);
return EXIT_FAILURE;
}
close(fd);
printf("data written '%s'\n",filename);
return EXIT_FAILURE;
}
/*
============================================================================
lseek success. Offset: 10
data written 'ff.txt'

============================================================================
*/