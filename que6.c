/*
============================================================================
Name : que6.c
Author : Rishu agrawal
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 6 sept, 2025.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
char str[100];
fscanf(stdin, "%s", str);
fprintf(stdout, "Output fron std output: %s\n", str);
return 0;
}
/*
============================================================================
Output fron std output: hello
============================================================================
*/