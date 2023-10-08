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
    nptr front;
    nptr rear;
}queue;

queue q;

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

//check if queue is empty
bool isEmpty(){
    return q.front==q.rear;
}


//initialize the queue
void init(){
    q.front=q.rear=NULL;
}

//place element at the end of the queue
void enqueue(int value)
{
    nptr element = createNode(value);
    if(!isEmpty()){
        if(q.front==NULL)
        {
            q.front = createNode(-1);
            q.front->next = q.rear;
        }
        q.rear->next=element;
        q.rear = element;
        return;
    }
    else
    {
        q.rear = element;
    }
}

int dequeue() {
    int returnValue = -1;
    if (!isEmpty()) {
        nptr current = q.front->next;
        returnValue = current->data;
        free(q.front);
        q.front = current;

        // If the queue becomes empty after dequeue
        if (q.front == NULL) {
            q.rear = NULL;
        }
    }
    return returnValue;
}

int main() {
    // Initialize the queue
    init();

    // Check if the queue is empty
    printf("Is the queue empty? %s\n", isEmpty() ? "Yes" : "No");

    // Enqueue some elements
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    // Check if the queue is empty
    printf("Is the queue empty? %s\n", isEmpty() ? "Yes" : "No");

    // Dequeue elements
    int dequeued = dequeue();
    printf("Dequeued element: %d\n", dequeued);

    // Check if the queue is empty
    printf("Is the queue empty? %s\n", isEmpty() ? "Yes" : "No");

    // Dequeue more elements
    dequeued = dequeue();
    printf("Dequeued element: %d\n", dequeued);

    dequeued = dequeue();
    printf("Dequeued element: %d\n", dequeued);

    dequeued = dequeue();
    printf("Dequeued element: %d\n", dequeued);

    // Check if the queue is empty
    printf("Is the queue empty? %s\n", isEmpty() ? "Yes" : "No");

}




