#define AUTHOR "TAIMOOR"
//run command: gcc -o exe.exe stackLinkedList.c.c -std=c99
#define STARTING_DATE "25-9-2016"
#define ENDING_DATE "15-10-2016"
#define PROGRAM_NAME "STACK IMPLEMENTATION"
#define BOOK_NAME "PROGRAMMING INTERVIEWS EXPOSED"
#define BOOK_PAGE 38
#define PROBLEM_NUMBER 1

// ACKNOWLEDGEMENT: Comments' source: PROGRAMMING INTERVIEWS EXPOSED

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


// you should declare a struct for each element with the apropriate data type 
// if the interviewer doesn't make any suggestions, storing void pointers is a good general purpose solution
typedef struct Element{
    struct Element * next;
    void * data;
} Element;

//to createStack and deleteStack functions provide implementation independent interface to the stack. You can change implementation, not the interface which is always a good thing
// To keep the implementation independence and consistency in mind, it's a good idea to have these functions return error codes (because altough a linkedlist won't return errors, changing implementation to a dynamic array would)
bool createStack ( Element ** stack );
bool deleteStack ( Element ** stack );

// Both the push and the pop operations change the first element in the list. The calling routine's stack pointer must be modified to reflect this change, but any change you make to the pointer that is passed to these functions won't be propagated back to the calling function. You can solve this problem by having both routines take a pointer to a pointer to the stack. This way you can change the calling routines pointer so that it continues to point at the first element of the list.
bool push ( Element ** stack , void * data);
bool pop ( Element ** stack , void ** data);
int top (Element ** stack);

//this function prints a single element data in the stack
void printElement(Element * element);

//this function prints the entire stack once from head to tail
void printStack(Element ** stack);

//this function pushes random values to the stack
void pushRandomValuesToStack(Element ** stack);

void printIntroduction();

int main(){
    printIntroduction();

    printf("Creating stack ...\n");
    Element ** stack;
    if(createStack(stack)){
        printf("Stack created ...\n");
    }else{
        printf("Stack not created ...\n\n");
    }

    printf("Pushing ...\n");

    //pushRandomValuesToStack(stack);

    int integer = rand() % 100;
    if (push(stack, &integer)){
         printf("Pushed: %d, ",integer);
    }

    int integer1 = rand() % 100;
    if (push(stack, &integer1)){
         printf("Pushed: %d, ",integer1);
    }

    int integer2 = rand() % 100;
    if (push(stack, &integer2)){
         printf("Pushed: %d, ",integer2);
    }

    int integer3 = rand() % 100;
    if (push(stack, &integer3)){
         printf("Pushed: %d, ",integer3);
    }

    int integer4 = rand() % 100;
    if (push(stack, &integer4)){
         printf("Pushed: %d, ",integer4);
    }

    int integer5 = rand() % 100;
    if (push(stack, &integer5)){
         printf("Pushed: %d, ",integer5);
    }

    int integer6 = rand() % 100;
    if (push(stack, &integer6)){
         printf("Pushed: %d, ",integer6);
    }

    printf("\n%d is now on top of the stack ...\n",top(stack));

    printStack(stack);

    printf("Poping ... \n");
    int  * data;
    if (pop(stack, &data)){
        printf("%d popped \n", *data);
    }

   if (pop(stack, &data)){
        printf("%d popped \n", *data);
    }

    if (pop(stack, &data)){
        printf("%d popped \n", *data);
    }


    printf("Deleting ...\n");
    if(deleteStack(stack)){
        printf("Stack deleted ...\n");
    }
    if (*stack == NULL){
        printf("Stack surely deleted ...\n");
    }

    return 0;
}

// this returns a stack
bool createStack ( Element ** stack ) {
    *stack = NULL;
    return true;
}

// although delete stack could call pop repeatedly, it's more efficient to simply traverse the data structure, freeing as you go  
bool deleteStack ( Element ** stack ) {
    // you must keep track of the next element while the current one is being deleted
    Element * next ; 
    while ( *stack ){
        next = ( *stack )->next;
        free(*stack);
        *stack = next;
    }
    return true;
}


// the push operation allocates the new element, checks for failure, sets the data of the new element, places it on top of the stack, and adjusts the pointer
bool push ( Element ** stack , void * data){


    // make an element and check if it has successfully been made
    Element * element = malloc(sizeof(Element));
    if (! element ) return false;

    // assign the data to the element
    element->data = data;
    element->next = *stack;
    *stack = element;
    return true;
}


bool pop ( Element ** stack, void ** data){
    // check if the stack exists
    if (!(*stack)) return false;

    //check if the stack is not empty
    //if (!(elem = *stack)) return false;

    //The pop operation checks if the stack is not empty, fetches the data from the top element, adjusts the stack pointer, and frees the element that is no longer needed.
    
    //PIE way
    Element * elem = *stack;
    if ( !elem ) return false;

    *data = elem->data;
    *stack = (*stack)->next;
    free(elem);

    return true;
}

int top(Element ** stack){
    int * i = (int*)(*stack)->data;
    return *i;
}

void printElement(Element * element){
    int * i = (int*)element->data;
    printf("%d, ",*i);
}

void printStack( Element ** stack ) {
    printf("Printing stack ... \n");
    Element *element = *stack;
    while (element != NULL) {
        printElement(element);
        element = element->next;
    }
}

void pushRandomValuesToStack(Element ** stack){
    

}

void printIntroduction(){
    printf("MADE BY: %s\nBOOK NAME: %s\nBOOK PAGE: %d\nPROGRAM NAME: %s\nSTARTING DATE: %s\nENDING DATE: %s\nPROBLEM NUMBER: %d\n",AUTHOR,BOOK_NAME, BOOK_PAGE, PROGRAM_NAME, STARTING_DATE, ENDING_DATE, PROBLEM_NUMBER);
}