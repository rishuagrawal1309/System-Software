/*
============================================================================
Name : que2.c
Author : Rishu agrawal
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory.
Date: 6 sept, 2025.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>

int main() {

printf("Process started. PID: %d\n", getpid());
 while(1) {
  sleep(1);
}
return 0;
}
/*
============================================================================
Process started. PID: 12345

============================================================================
*/