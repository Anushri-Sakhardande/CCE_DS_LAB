#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

typedef struct TNode *Tptr;
typedef struct TNode
{
    int data;
    Tptr leftchild;
    Tptr rightchild;
}TNode;


//Create nodes in the tree
Tptr createNode(int val)
{
    Tptr temp =(Tptr)malloc(sizeof(TNode));
    temp->data = val;
    temp->leftchild = temp->rightchild = NULL;
    return temp;
}

//create the binary search tree
void createBST(Tptr *root)
{
    int N, i, val;
    Tptr current, previous;
    printf("Enter the number of nodes: ");
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        printf("Enter a unique value: ");
        scanf("%d", &val);
        Tptr temp = createNode(val);
        if (!*root)
        {
            *root = temp;
        }
        else
        {
            current = *root;
            previous = NULL;
            while (current)
            {
                previous = current;
                if (val < current->data)
                {
                    current = current->leftchild;
                }
                else if (val > current->data)
                {
                    current = current->rightchild;
                }
                if (val == previous->data)
                {
                    printf("Duplicate\n");
                    free(temp);
                    return;
                }
            }
            if (val < previous->data)
            {
                previous->leftchild = temp;
            }
            else
            {
                previous->rightchild = temp;
            }
        }
    }
}

//insert node into the BST
void insertBST(Tptr *root, int val)
{
    if (!*root)
    {
        Tptr temp = createNode(val);
        *root = temp;
    }
    else
    {
        if (val < (*root)->data)
        {
            insertBST(&((*root)->leftchild), val);
        }
        else if (val > (*root)->data)
        {
            insertBST(&((*root)->rightchild), val);
        }
        else
        {
            printf("Duplicate\n");
        }
    }
}


//find the node containing minimum value
Tptr findMinimum(Tptr root){
    if(root == NULL){
        return root;
    }
    while(root->leftchild!=NULL){
        root = root->leftchild;
    }
    return root;
}

//delete node from Binary Search Tree
Tptr deleteBST(int key,Tptr root)
{
    if(root==NULL)
    {
        printf("Not present");
        return NULL;
    }
    if(key<root->data)//if key is smaller than root send to the left subtree
    {
        root->leftchild = deleteBST(key,root->rightchild);
    }
    else if(key>root->data)//if root is smaller than key send to the right subtree
    {
        root->rightchild = deleteBST(key,root->rightchild);
    }
    else 
    {
        Tptr temp;
        if(root->leftchild!=NULL && root->rightchild!=NULL) // if element to be deleted has both children
        {
            temp = findMinimum(root->rightchild);
            root->data = temp->data;
            root->rightchild = deleteBST(temp->data,root->rightchild);
        }
        else // if element to be deleted has one child
        {
            temp = root;
            if(root->leftchild==NULL)
            {
                root = root->rightchild;
            }
            else if(root->rightchild==NULL)
            {
                root = root->leftchild;
            }
            free(temp);
        }
    }
    return root;
}

void search(Tptr root,int key,bool *flag){
    if (root) {
        if(root->data == key)
        {
            *flag = true;
            return;
        }
        search(root->leftchild,key,flag);
        search(root->rightchild,key,flag);
    }
}

// Function for inorder Traversal of tree.
void printInorder(Tptr root)
{
    if (root) {
        printInorder(root->leftchild);
        printf("%d ",root->data);
        printInorder(root->rightchild);
    }
}

int main() {
    // Initialize the root pointer to NULL
    Tptr root = NULL;

    int choice, key;
    do {
        printf("\nBinary Search Tree Menu:\n");
        printf("1. Create a BST\n");
        printf("2. Insert a node\n");
        printf("3. Delete a node\n");
        printf("4. Search for a node\n");
        printf("5. Print BST in inorder\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createBST(&root);
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &key);
                insertBST(&root, key);
                break;
            case 3:
                printf("Enter the value to delete: ");
                scanf("%d", &key);
                root = deleteBST(key, root);
                break;
            case 4:
                printf("Enter the value to search: ");
                scanf("%d", &key);
                bool found = false;
                search(root, key, &found);
                if (found) {
                    printf("Value %d is found in the BST.\n", key);
                } else {
                    printf("Value %d is not found in the BST.\n", key);
                }
                break;
            case 5:
                printf("Inorder Traversal of the BST: ");
                printInorder(root);
                printf("\n");
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    // Free memory for the BST nodes before exiting
    // You should implement a function to free the memory properly.

    return 0;
}
