/*
============================================================================
Name : que1.c
Author : Rishu agrawal
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
Date: 6 sept, 2025.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<errno.h>
#include<string.h>

int main(){
  const char *target_file="original.txt";
  const char *soft_link="soft_link.txt";
  const char *hard_link="hard_link.txt";
  const char *fifo_path="myfifo";

 FILE *fp=fopen(target_file,"w");
if(fp==NULL){
perror("Error creating target file");
return 1;
}
fprintf(fp, "This is the original file.\n");
fclose(fp);

if(symlink(target_file, soft_link)==-1){
 perror("Error creating symbolic link");
return 1;
} 
 printf("Symbolic Link '%s' -> '%s' created successfully. \n", soft_link, target_file);


if(link(target_file,hard_link)==-1){
perror("error creating hard link");
return 1;
} 
printf("hard link '%s' -> '%s' created successfully.\n", hard_link, target_file);



if(mkfifo(fifo_path, 0666)==-1){
perror("mkfifo");
return 1;
} 
printf("FIFO '%s' created successfully.\n", fifo_path);

return 0;
}

/*
============================================================================
Symbolic Link 'soft_link.txt' -> 'original.txt' created successfully. 
hard link 'hard_link.txt' -> 'original.txt' created successfully.
FIFO 'myfifo' created successfully.

============================================================================
*/