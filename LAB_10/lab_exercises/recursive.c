#include "tree.h"

// Function for inorder Traversal of tree.
void printInorder(Tptr root)
{
    if (root != NULL) {
        printInorder(root->leftchild);
        printf("%d",root->data);
        printInorder(root->rightchild);
    }
}