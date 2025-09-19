/*
============================================================================
Name : que5.c
Author : Rishu agrawal
Description : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
Date: 6 sept, 2025.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
int main(){
const char *file[5] ={ "f0.txt","f1.txt", "f2.txt","f3.txt","f4.txt"};
int fd[5];
for(int i=0;i<5;i++){
fd[i]=open(file[i], O_CREAT|O_RDWR, 0644);
if(fd[i]==-1){
perror("open");
exit(1);
}
else{
printf("opened %s with fd %d\n", file[i],fd[i]);
}
}

while(1){
sleep(10);
}

for(int i=0;i<5;i++)
{
close(fd[i]);
}
return 0;
}
/*
============================================================================
opened f0.txt with fd 3
opened f1.txt with fd 4
opened f2.txt with fd 5
opened f3.txt with fd 6
opened f4.txt with fd 7

============================================================================
*/