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

    Tptr root = NULL;
    int choice, value;

    do {
        printf("\nBinary Search Tree Operations\n");
        printf("1. Insert Node\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Insert Node
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = createRecursive(root, value);
                break;

            case 2:
                // Inorder Traversal
                printf("Inorder Traversal: ");
                printInorder(root);
                printf("\n");
                break;

            case 3:
                // Preorder Traversal
                printf("Preorder Traversal: ");
                printPreorder(root);
                printf("\n");
                break;

            case 4:
                // Postorder Traversal
                printf("Postorder Traversal: ");
                printPostorder(root);
                printf("\n");
                break;

            case 5:
                // Exit
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}