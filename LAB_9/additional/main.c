#include <stdio.h>
#include <stdlib.h>

typedef struct pnode* pptr;
typedef struct pnode
{
    int coeff;
    int expo;
    pptr next;
} pnode;

// create node in the linked list
pptr createNode(int coeff,int expo)
{
    pptr temp = (pptr)malloc(sizeof(pnode));
    if (temp == NULL)
    {
        printf("Heap is full");
        free(temp);
        exit(0);
    }
    temp->coeff = coeff;
    temp->expo = expo;
    temp->next = NULL;
    return temp;
}

//insert element at the end of the linked list
void insertEnd(int coeff,int expo,pptr* head)
{
    pptr temp = createNode(coeff, expo);
    if (*head == NULL)
    {
        *head = temp;
    }
    else
    {
        temp->next = (*head)->next;
        (*head)->next = temp;
        *head = temp;
    }
}


void attach(int coeff,int expo,pptr* rear)
{
    pptr temp = createNode(coeff, expo);
    temp->next = (*rear)->next;
    (*rear)->next = temp;
    *rear = temp;
}

pptr polyAdd(pptr A,pptr B)
{
    pptr C,rear,temp;
    rear = (pptr)malloc(sizeof(pnode));
    C = rear;
    while(A && B)
    {
        int diff = A->expo - B->expo;

        //A->expo < B->expo
        if(diff<0)
        {
            attach(B->coeff,B->expo,&rear);
            B = B->next;
            break;
        }

        //A->expo > B->expo
        else if(diff>0)
        {
            attach(A->coeff,A->expo,&rear);
            A = A->next;
            break;
        }

        //A->expo = B->expo
        else
        {
            int sum = A->coeff + B->coeff;
            if(sum)
            {
                attach(sum,A->expo,&rear);
            }
            A = A->next;
            B = B->next;
        }
    }

    //attach remaining nodes for A and B
    for(;A;A = A->next)
    {
        attach(A->coeff,A->expo,&rear);
    }
    for(;B;B=B->next)
    {
        attach(B->coeff,B->expo,&rear);
    }

    temp = C;
    C = C->next;
    free(temp);
    return C;
}

int main()
{
    pptr A,B;
    A = B = NULL;
    insertEnd(3,3,&A);
    insertEnd(4,2,&A);
    insertEnd(1,0,&A);

    insertEnd(6,4,&B);
    insertEnd(5,2,&B);
    insertEnd(4,1,&B);


    pptr C = polyAdd(A,B);
    pptr current = C;
    while(current)
    {
        printf("%d,%d->",current->coeff,current->expo);
        current = current->next;
    }
    return 0;
}
