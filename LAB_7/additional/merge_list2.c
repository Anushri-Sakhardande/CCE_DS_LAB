#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} node;
typedef struct node *nptr;

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

// insert a node at the end of the list
void insertEnd(nptr *head,int val)
{
    nptr temp = createNode(val);

    // if the list is empty
    if (*head == NULL)
    {

        *head = temp;
        return;
    }

    nptr current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = temp;
}

nptr merge(nptr xHead , nptr yHead)
{
    nptr mHead=NULL;
    int i;
    nptr yCurrent = yHead;
    nptr xCurrent = xHead;
    nptr mCurrent = xCurrent;
    mHead = mCurrent;
    xCurrent = xCurrent->next;
    //appennd alternate nodes to list
    while(yCurrent!=NULL)
    {
        mCurrent->next = yCurrent;
        yCurrent = yCurrent->next;
        mCurrent = mCurrent->next;
        mCurrent->next = xCurrent;
        xCurrent = xCurrent->next;
        mCurrent = mCurrent->next;
    }
    //append remaining nodes of x
    while(xCurrent!=NULL)
    {
        mCurrent->next = xCurrent;
        xCurrent = xCurrent->next;
        mCurrent = mCurrent->next;
    }
    return mHead;
}

int main()
{
    // Create and populate the first linked list (xHead)
    nptr xHead=NULL;
    insertEnd(&xHead,1);
    insertEnd(&xHead,2);
    insertEnd(&xHead,3);
    insertEnd(&xHead,4);

    // Create and populate the second linked list (yHead)
    nptr yHead=NULL;
    insertEnd(&yHead,5);
    insertEnd(&yHead,6);

    // Merge the two linked lists
    nptr mergedHead = merge(xHead, yHead);

    // Print the merged linked list
    nptr current = mergedHead;
    printf("Merged List: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}