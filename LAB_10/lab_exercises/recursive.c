#include "tree.h"

Tptr createRecursive(Tptr root,int value)
{
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->leftchild = createRecursive(root->leftchild, value);
    } else if (value > root->data) {
        root->rightchild = createRecursive(root->rightchild, value);
    }

    return root;
}

// Function for postorder Traversal of tree.
void printPostorder(Tptr root)
{
    if (root) {
        printPostorder(root->leftchild);
        printPostorder(root->rightchild);
        printf("%d ",root->data);
    }
}

// Function for preorder Traversal of tree.
void printPreorder(Tptr root)
{
    if (root) {
        printf("%d ",root->data);
        printPreorder(root->leftchild);
        printPreorder(root->rightchild);
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

    // Insert nodes into the binary tree
    root = createRecursive(root,5);
    root = createRecursive(root,3);
    root = createRecursive(root,8);
    root = createRecursive(root,2);
    root = createRecursive(root,4);

    // Print the binary tree using different tree traversal methods
    printf("Binary Tree (In-Order): ");
    printInorder(root);
    printf("\n");

    printf("Binary Tree (Pre-Order): ");
    printPreorder(root);
    printf("\n");

    printf("Binary Tree (Post-Order): ");
    printPostorder(root);
    printf("\n");

    return 0;
}