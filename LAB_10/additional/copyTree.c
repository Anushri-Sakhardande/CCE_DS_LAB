#include <stdio.h>
#include <stdlib.h>

typedef struct TNode *Tptr;
typedef struct TNode
{
    int data;
    Tptr left;
    Tptr right;
}TNode;

Tptr createNode(int data) {
    Tptr newNode = (Tptr)malloc(sizeof(TNode));
    if (newNode == NULL) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Tptr copyTree(Tptr original) {
    if (original == NULL) {
        return NULL;
    }

    Tptr newNode = createNode(original->data);
    newNode->left = copyTree(original->left);  
    newNode->right = copyTree(original->right); 

    return newNode;
}

void printInorder(Tptr root) {
    if (root != NULL) {
        printInorder(root->left);
        printf("%d ", root->data);
        printInorder(root->right);
    }
}

int main() {
    Tptr originalRoot = createNode(1);
    originalRoot->right = createNode(2);
    originalRoot->left = createNode(3);
    originalRoot->left->left= createNode(0);
    originalRoot->right->left = createNode(4);
    originalRoot->right->right = createNode(5);

    printf("Original Tree (Inorder Traversal): ");
    printInorder(originalRoot);

    Tptr copiedRoot = copyTree(originalRoot);

    printf("\nCopied Tree (Inorder Traversal): ");
    printInorder(copiedRoot);
    printf("\n");

    return 0;
}