#include <stdio.h>
#include <stdlib.h>

typedef struct TNode *Tptr;
typedef struct TNode
{
    int data;
    Tptr left;
    Tptr right;
}TNode;

// Create Node for the Binary Tree
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

// Function to check if two trees are mirror images of each other
int areMirror(Tptr tree1, Tptr tree2) {
    // both tree empty, mirror
    if (tree1 == NULL && tree2 == NULL) {
        return 1;
    }

    //  one tree empty, not mirror
    if (tree1 == NULL || tree2 == NULL) {
        return 0;
    }

    // check recursively their subtrees
    return (tree1->data == tree2->data) && areMirror(tree1->left, tree2->right) && areMirror(tree1->right, tree2->left);
}

int main() {
    Tptr root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    root1->left->left = createNode(4);
    root1->left->right = createNode(5); 

    Tptr root2 = createNode(1);
    root2->left = createNode(3);
    root2->right = createNode(2);
    root2->right->left = createNode(5);
    root2->right->right = createNode(4);

    if (areMirror(root1, root2)) {
        printf("The trees are mirror images.\n");
    } else {
        printf("The trees are not mirror images.\n");
    }

    return 0;
}