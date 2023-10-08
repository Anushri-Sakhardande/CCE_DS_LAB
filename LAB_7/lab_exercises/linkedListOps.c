#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} node;
typedef struct node *nptr;
nptr head = NULL;

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

// insert element before the existing element
void insertBefore(int value, int beforeValue)
{
    // in case list is empty
    if (head == NULL)
    {
        nptr temp = createNode(value);
        head = temp;
        return;
    }
    bool found = false;
    nptr current = head;
    nptr previous = NULL;
    //iterate to find the node
    while (current != NULL)
    {
        if (current->data == beforeValue)
        {
            found = true;
            break;
        }
        previous = current;
        current = current->next;
    }
    //if element is found
    if (found)
    {
        nptr temp = createNode(value);
        // in case to be inserted before first element
        if (previous == NULL)
        {
            temp->next = current;
            head = temp;
        }
        else
        {
            temp->next = current;
            previous->next = temp;
        }
    }
    //if node is not found
    else
    {
        printf("Node not found in list");
    }
}

// insert element after the existing element
void insertAfter(int value, int afterValue)
{
    // in case list is empty
    if (head == NULL)
    {
        nptr temp = createNode(value);
        head = temp;
        return;
    }

    bool found = false;
    nptr current = head;
    //iterate to find node
    while (current != NULL)
    {
        if (current->data == afterValue)
        {
            found = true;
            break;
        }
        current = current->next;
    }
    //if node is found we insert
    if (found)
    {
        nptr temp = createNode(value);
        temp->next = current->next;
        current->next = temp;
    }
    //if node is not found
    else
    {
        printf("Node not found in list");
    }
}

// delete node for list
void deleteNode(int value)
{
    // in case list is empty
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }

    bool found = false;
    nptr current = head;
    nptr previous = NULL;
    //iterate to find node
    while (current != NULL)
    {
        if (current->data == value)
        {
            found = true;
            break;
        }
        previous = current;
        current = current->next;
    }
    //if found we delete
    if (found)
    {
        if (previous != NULL)
        {
            previous->next = current->next;
        }
        // if element to be deleted is the first element
        else
        {
            head = current->next;
        }
        free(current);
    }
    //if element not found
    else
    {
        printf("Element not present");
    }
}

// traverse the list
void traverse()
{
    // in case list is empty
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }

    nptr current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    free(current);
    printf("\n");
}

// reverse linked list
void reverse()
{
    // in case list is empty
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }

    nptr current = head;
    nptr previous = NULL;
    while (current != NULL)
    {
        nptr currentNext = current->next;
        current->next = previous;
        previous = current;
        current = currentNext;
    }
    head = previous;
}

// sort a linked list
void sort()
{
    // in case list is empty or has only one element
    if (head == NULL || head->next == NULL)
    {
        printf("List is empty or only one element");
        return;
    }
    nptr outerCurrent = head;
    while (outerCurrent != NULL)
    {
        nptr innerPrevious = NULL;
        nptr innerCurrent = head;
        while (innerCurrent->next != NULL)
        {
            nptr innerNext = innerCurrent->next;
            if (innerCurrent->data > innerNext->data)
            {
                if (innerPrevious != NULL)
                {
                    innerPrevious->next = innerNext;
                }
                // Update head if needed
                else
                {
                    head = innerNext;
                }
                innerCurrent->next = innerNext->next;
                innerNext->next = innerCurrent;
                innerPrevious = innerNext;
            }
            else
            {
                innerPrevious = innerCurrent;
                innerCurrent = innerNext;
            }
        }
        outerCurrent = outerCurrent->next;
    }
}

// delete alternate nodes
void deleteAlternate()
{
    // in case list is empty
    if (head == NULL || head->next==NULL)
    {
        printf("List is empty or only one element");
        return;
    }

    nptr current = head;
    while(current!=NULL && current->next != NULL)
    {
        nptr currentNext = current->next;
        current->next = currentNext->next;
        free(currentNext);
        current=current->next;
    }
}

// insert into sorted array
void insertSorted(int value)
{
    nptr temp = createNode(value);
    nptr current = head;
    nptr previous = NULL;
    //if the list is empty,we insert as the first
    if (head == NULL)
    {
        head = temp;
        return;
    }
    while (current != NULL && current->data <= value)
    {
        previous = current;
        current = current->next;
    }
    //insert at the beginning of the list 
    if (previous == NULL)
    {
        temp->next = head;
        head = temp;
    }
    //insert in the middle or at the end of the list.
    else
    {
        temp->next = previous->next;
        previous->next = temp;
    }
}

int main()
{
    int choice;
    int value1, value2;
    printf("Enter\n 1)Insert an element before another element in the existing list\n 2) Insert an element after another element in the existing list\n 3) Delete a given element from the list\n 4) Traverse the list\n 5) Reverse the list\n 6) Sort the list\n 7) Delete every alternate node in the list\n 8) Insert an element in a sorted list such that the order is maintained\n");
    scanf("%d",&choice);
    do
    {
        switch (choice)
        {
        case 1:
            printf("Enter element to be entered and before element:");
            scanf("%d%d", &value1,&value2);
            insertBefore(value1,value2);
            break;
        case 2:
            printf("Enter element to be entered and after element:");
            scanf("%d%d", &value1, &value2);
            insertAfter(value1, value2);
            break;
        case 3:
            printf("Enter element to be deleted:");
            scanf("%d", &value1);
            deleteNode(value1);
            break;
        case 4:
            traverse();
            break;
        case 5:
            reverse();
            traverse();
            break;
        case 6:
            sort();
            traverse();
            break;
        case 7:
            deleteAlternate();
            traverse();
            break;
        case 8:
            printf("Enter element to be entered:");
            scanf("%d", &value1);
            insertSorted(value1);
            traverse();
            break;
        }
        printf("\nEnter 0 to terminate or another number to continue");
        scanf("%d", &choice);
    }
    while (choice != 0);
}