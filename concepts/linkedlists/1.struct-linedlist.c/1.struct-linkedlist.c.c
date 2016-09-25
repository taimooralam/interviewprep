//Made by Taimoor Alam
//to run use gcc -o exe 1.\ struct-linkedlist\ c.c -std=c99
#include <stdio.h>

//The simplest useful singly linked list
typedef struct IntElement {
    struct IntElement *next;
    int data;
} IntElement;

// this function creates a linked list and returns the item
IntElement* createALinkedList(int n){
    IntElement* head = NULL;
    IntElement* prev = head;
    for (int i = 0 ; i < n ; i++){
        IntElement *element = (IntElement*)malloc(sizeof(IntElement));
        element->data = i;
        element->next = NULL;
        if (i == 0){
            head = element;
            prev = element;
        }else{
            prev->next = element;
            prev = prev->next;
        }
    }
    return head;
}

void printLinkedList(IntElement *head){
    for (IntElement * pointer = head; pointer->next != NULL ; pointer=pointer->next){
        printf("The element data is %d\n", pointer->data);
    }
}

//the main function creates and prints a linkedlist
void main(){
    printf("This is the main function.\n");
    IntElement* element = createALinkedList(10);
    printLinkedList(element);
    return;
}