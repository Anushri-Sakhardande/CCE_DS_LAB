#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct dNode
{
    int data;
    struct dNode* previous;
    struct dNode* next;
}dNode;
typedef struct dNode* nptr;

//create a node
nptr createNode(int value)
{
    nptr temp = (nptr)malloc(sizeof(dNode));
    if(temp == NULL)
    {
        printf("Heap is full\n");
    }
    temp->data = value;
    temp->next = NULL;
    temp->previous = NULL;
    return temp;
}

//Insert an element at the rear end of the list
void insertRear(int value,nptr* head)
{
    nptr temp = createNode(value);
    //if first element
    if(*head==NULL)
    {
        *head = temp;
    }
    else
    {
        nptr current = *head;
        while(current->next!=NULL)
        {
            current = current->next;
        }
        temp->previous = current;
        current->next = temp;
    }
}

//check if the nodes are already present in the list
bool isPresent(int data,nptr head)
{
    nptr current = head;
    bool ret;
    while(current)
    {
        if(current->data==data)
        {
            ret = true;
            break;
        }
        current = current->next;
    }
    return ret;
}

//find the union of the two lists
nptr unionList(nptr head1 , nptr head2)
{
    nptr result = NULL;
    nptr current1 = head1, current2 = head2;
    while (current1!=NULL)
    {
        insertRear(current1->data,&result);
        current1 = current1->next;
    }
    while(current2!=NULL)
    {
        if(!isPresent(current2->data,result))
        {
            insertRear(current2->data,&result);
        }
        current2 = current2->next;
    }
    return result;
}

//find the intersection of the two lists
nptr intersectionList(nptr head1 , nptr head2)
{
    nptr result = NULL;
    nptr current1 = head1, current2 = head2;
    while (current1!=NULL)
    {
        if(isPresent(current1->data,head2))
        {
            insertRear(current1->data,&result);
        }
        current1 = current1->next;
    }
    return result;
}

int main()
{
    // Create the first doubly linked list
    nptr head1 = NULL;
    insertRear(1, &head1);
    insertRear(2, &head1);
    insertRear(3, &head1);

    // Create the second doubly linked list
    nptr head2 = NULL;
    insertRear(2, &head2);
    insertRear(3, &head2);
    insertRear(4, &head2);

    // Find and print the union of the two lists
    nptr unionResult = unionList(head1, head2);
    printf("Union of the lists: ");
    nptr current = unionResult;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Find and print the intersection of the two lists
    nptr intersectionResult = intersectionList(head1, head2);
    printf("Intersection of the lists: ");
    current = intersectionResult;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}
