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

nptr head;
nptr tail;

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
void insertRear(int value)
{
    nptr temp = createNode(value);
    //if first element
    if(head==NULL && tail==NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        temp->previous = tail;
        tail = temp;
    }
}

//Delete an element from the rear end of the list
void deleteRear()
{
    //if first element
    if(head==NULL && tail==NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        nptr previousNode = tail->previous;
        previousNode->next = NULL;
        free(tail);
        tail = previousNode;
    }
}

//Insert an element at a given position of the list
void insertPosition(int value,int position)
{
    //if list is empty
    if(head==NULL && tail==NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        int i;
        nptr temp = createNode(value);
        nptr current = head;
        //iterate till we reach position
        for(i=0;current!=NULL && i<position-1;i++)
        {
            current = current->next;
        }
        //if last element or position outside boundary append to end
        if(current==NULL || current->next==NULL)
        {
            insertRear(value);
        }
        //if first element
        else if(current==head)
        {
            temp->next = head;
            head->previous = temp;
            head = temp;
        }
        //if not head or rear
        else
        {
            nptr currentNext = current->next;
            current->next = temp;
            temp->previous = current;
            temp->next = currentNext;
            currentNext->previous = temp;
        }
    }
}

//Delete an element from a given position of the list
void deletePosition(int position)
{
    //list is empty
    if(head==NULL && tail==NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        int i;
        nptr current = head;
        //iterate till we reach position
        for(i=0;i<position-1 && current!=NULL;i++)
        {
            current = current->next;
        }
        //if last element or position outside boundary delete to end
        if(current==NULL || current->next==NULL)
        {
            deleteRear();
        }
        //if first element
        else if(current==head)
        {
            head = current->next;
            head->previous = NULL;
            free(current);
        }
        //if not head or rear
        else
        {
            nptr currentPrevious = current->previous;
            nptr currentNext = current->next;
            currentPrevious->next = currentNext;
            currentNext->previous = currentPrevious;
            free(current);
        }
    }
}

//Insert an element after another element
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
        temp->previous = current;
        current->next->previous = temp;
        current->next = temp;
    }
    //if node is not found
    else
    {
        printf("Node not found in list");
    }
}

//Insert an element before another element
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
    //iterate to find the node
    while (current != NULL)
    {
        if (current->data == beforeValue)
        {
            found = true;
            break;
        }
        current = current->next;
    }
    //if element is found
    if (found)
    {
        nptr temp = createNode(value);
        // in case to be inserted before first element
        if (current->previous == NULL)
        {
            temp->next = current;
            head = temp;
        }
        else
        {
            temp->next = current;
            temp->previous = current->previous;
            current->previous->next = temp;
            current->previous = temp;
        }
    }
    
    //if node is not found
    else
    {
        printf("Node not found in list");
    }
}

//traverse the list
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

void reverse()
{
    // in case list is empty
    if (head == NULL || head->next==NULL)
    {
        printf("List is empty or only one element");
        return;
    }

    nptr temp = NULL;
    nptr current = head;
 
    while (current != NULL) {
        temp = current->previous;
        current->previous = current->next;
        current->next = temp;
        current = current->previous;
    }
 
    if (temp != NULL)
        head = temp->previous;
}

int main()
{
    int choice, value, position, afterValue, beforeValue;
    
    head = NULL;
    tail = NULL;
    
    while (1)
    {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at the rear end\n");
        printf("2. Delete from the rear end\n");
        printf("3. Insert at a given position\n");
        printf("4. Delete from a given position\n");
        printf("5. Insert after a value\n");
        printf("6. Insert before a value\n");
        printf("7. Traverse the list\n");
        printf("8. Reverse the list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertRear(value);
                break;
                
            case 2:
                deleteRear();
                break;
                
            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                insertPosition(value, position);
                break;
                
            case 4:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deletePosition(position);
                break;
                
            case 5:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the value to insert after: ");
                scanf("%d", &afterValue);
                insertAfter(value, afterValue);
                break;
                
            case 6:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the value to insert before: ");
                scanf("%d", &beforeValue);
                insertBefore(value, beforeValue);
                break;
                
            case 7:
                printf("Doubly Linked List: ");
                traverse();
                break;
                
            case 8:
                reverse();
                printf("Doubly Linked List has been reversed.");
                break;
                
            case 9:
                printf("Exiting program.\n");
                exit(0);
                break;
                
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    
    return 0;
}
