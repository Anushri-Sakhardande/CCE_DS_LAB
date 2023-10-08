#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node *nptr;
typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct{
    nptr top;
}stack;

stack s;

// create node in the linked list
nptr createNode(int value)
{
    nptr temp = (nptr)malloc(sizeof(node));
    if (temp == NULL)
    {
        printf("Heap is full");
        free(temp);
        exit(0);
    }
    temp->data = value;
    temp->next = NULL;
    return temp;
}

//check if list is empty
bool isEmpty(){
    return s.top==NULL;
}

//initialize list
void init(){
    s.top=NULL;
}


//push element onto the stack
void Push(int value){
    nptr element = createNode(value);
    if(!isEmpty()){
        element->next=s.top;
        s.top = element;
        return;
    }
    s.top = element;
}

//pop element from stack
int Pop(){
    int returnValue = -1;
    if (!isEmpty())
    {
        returnValue = s.top->data;
        nptr newTop = s.top->next;
        free(s.top);
        s.top = newTop;
    }
    return returnValue;
}

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Your stack implementation here

int main() {
    // Initialize the stack
    init();

    // Check if the stack is empty
    printf("Is the stack empty? %s\n", isEmpty() ? "Yes" : "No");

    // Push some elements onto the stack
    Push(1);
    Push(2);
    Push(3);
    Push(4);

    // Check if the stack is empty
    printf("Is the stack empty? %s\n", isEmpty() ? "Yes" : "No");

    // Pop elements from the stack
    int popped = Pop();
    printf("Popped element: %d\n", popped);

    // Check if the stack is empty
    printf("Is the stack empty? %s\n", isEmpty() ? "Yes" : "No");

    // Pop more elements from the stack
    popped = Pop();
    printf("Popped element: %d\n", popped);

    popped = Pop();
    printf("Popped element: %d\n", popped);

    popped = Pop();
    printf("Popped element: %d\n", popped);

    // Check if the stack is empty
    printf("Is the stack empty? %s\n", isEmpty() ? "Yes" : "No");

    return 0;
}
