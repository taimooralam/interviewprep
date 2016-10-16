#define AUTHOR "TAIMOOR"
//run command: g++ stackImplementation.cpp -o exepp.exe -std=c++11
#define STARTING_DATE "16-10-2016"
#define ENDING_DATE "16-10-2016"
#define PROGRAM_NAME "STACK IMPLEMENTATION"
#define BOOK_NAME "PROGRAMMING INTERVIEWS EXPOSED"
#define BOOK_PAGE 38
#define PROBLEM_NUMBER 1

// ACKNOWLEDGEMENT: Comments' source: PROGRAMMING INTERVIEWS EXPOSED

#include <iostream>
#include <stdio.h>
using namespace std;

//The file is about building a stack using linkedlist via OOP in C++
class Stack {
    public: 
        Stack () : head(NULL) {};
        ~Stack();
        void push(void * data);
        void * pop();
        void printStack();

    protected:
        class Element{

            public:
                Element ( Element * n , void * d ) : next(n), data(d) {}
                Element *getNext() const { return next; }
                void * value() const { return data; }

            private:
                Element * next;
                void * data;
        };

        Element * head;
};


Stack::~Stack() {
    while(head){
        Element * next = head->getNext();
        delete head;
        head = next;
    }
    cout << "Stack deleted ..." << endl;
}

void Stack::push( void * data ){
    //Allocation error will throw exception
    // TODO: find out how to handle exception in C++
    Element * element = new Element(head,data);
    head = element;
    cout << "Element pused ... " << endl;
}

void * Stack::pop(){
    Element *popElement = head;
    void *data;

    /*Assume that the stack error exception class is defined elsewhere*/
    if (head == NULL){
        cout << "Stack error" << endl;
    }

    data = head->value();
    head = head->getNext();
    delete popElement;
    return data;
}

void Stack::printStack()
{
    Element * element = head;
    while(element){
        cout << *(int *)element->value() << endl;
        Element * next = element->getNext();
        element = next;
    }
}

void printIntroduction();

int main(){

    printIntroduction();

    Stack * stack = new Stack();
    int integer = rand() % 100;
    stack->push(&integer);
    int integer2 = rand() % 100;
    stack->push(&integer2);

    stack->printStack();
    delete stack;



    
    return 0;
}

void printIntroduction(){
    printf("MADE BY: %s\nBOOK NAME: %s\nBOOK PAGE: %d\nPROGRAM NAME: %s\nSTARTING DATE: %s\nENDING DATE: %s\nPROBLEM NUMBER: %d\n",AUTHOR,BOOK_NAME, BOOK_PAGE, PROGRAM_NAME, STARTING_DATE, ENDING_DATE, PROBLEM_NUMBER);
}