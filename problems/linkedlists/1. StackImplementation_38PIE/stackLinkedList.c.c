#define AUTHOR "TAIMOOR"
//run command: gcc -o exe.exe stackLinkedList.cc -std=c99
#define STARTING_DATE "25-9-2016"
#define ENDING_DATE "25-9-2016"
#define PROGRAM_NAME "STACK IMPLEMENTATION"
#define BOOK_NAME "PROGRAMMING INTERVIEWS EXPOSED"
#define BOOK_PAGE 38
#define PROBLEM_NUMBER 1

#include <stdio.h>

void printIntroduction(){
    printf("MADE BY: %s\nBOOK NAME: %s\nBOOK PAGE: %d\nPROGRAM NAME: %s\nSTARTING DATE: %s\nENDING DATE: %s\nPROBLEM NUMBER: %d\n",AUTHOR,BOOK_NAME, BOOK_PAGE, PROGRAM_NAME, STARTING_DATE, ENDING_DATE, PROBLEM_NUMBER);
}

int main(){
    printIntroduction();
    return 0;
}