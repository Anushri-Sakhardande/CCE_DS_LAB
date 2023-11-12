#include "tree.h"

//print node elements in inorder
void IterativeInorder(Tptr node)
{
    for(;;)
    {
        for(; node;node = node->leftchild)
        {
            Push(node);
        }
        node = Pop();
        if(node == NULL)
        {
            break;
        }
        printf("%d ",node->data);
        node = node->rightchild;
    }

}

//print node elements in preorder
void IterativePreorder(Tptr node)
{
    for(;;)
    {
        for(; node;node = node->leftchild)
        {
            Push(node);
            printf("%d ",node->data);
        }
        node = Pop();
        if(node == NULL)
        {
            break;
        }
        node = node->rightchild;
    }
}

//print node elements in postorder
void IterativePostorder(Tptr node)
{
    for(;;)
    {
        if(node)
        {
            Push(node);
            node = node->leftchild;
        }
        else
        {
            if(!peek())
            {
                break;
            }
            Tptr temp = peek()->rightchild;
            if(temp==NULL)
            {
                temp = Pop();
                printf("%d ",temp->data);
                while(!isEmpty() && temp==peek()->rightchild)
                {
                    temp = Pop();
                    printf("%d ",temp->data);
                }
            }
            else
            {
                node = temp;
            }
        }
    }
}

//Return the parent of a given node
Tptr ParentNode(Tptr node,int target)
{
    for(;;)
    {
        for(; node;node = node->leftchild)
        {
            Push(node);
        }
        node = Pop();
        if(node == NULL)
        {
            break;
        }
        if ((node->leftchild && node->leftchild->data == target) || (node->rightchild && node->rightchild->data == target)) {
            return node;
        }
        node = node->rightchild;
    }
}

//Find the depth of a given tree
int treeDepth(Tptr node)
{
    if (node == NULL) {
        return 0; // The depth of an empty tree is 0
    }

    int leftDepth = treeDepth(node->leftchild);
    int rightDepth = treeDepth(node->rightchild);
    return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
}

//print all the ancestors of a node
bool Ancestors(Tptr node, int target)
{
  if (node == NULL)
     return false;
 
  if (node->data == target)
     return true;
 
  if (Ancestors(node->leftchild, target) || Ancestors(node->rightchild, target) )
  {
    printf("%d ",node->data);
    return true;
  }

  return false;
}

//count the number of leaf nodes in a tree
int leafNodes(Tptr node)
{
    if (node == NULL) {
        printf("Tree is empty.\n");
        return 0;
    }
    int totalCount = 0;
    for (;;) {
        for (; node; node = node->leftchild) {
            Push(node);
        }
        node = Pop();
        if (node == NULL) {
            break;
        }
        if (node->leftchild == NULL && node->rightchild == NULL) {
            totalCount++;
        }
        node = node->rightchild;
    }

    return totalCount;
}

int main()
{
    int N;
    root = NULL;
    int choice, target;

    do {
        printf("\nBinary Tree Operations\n");
        printf("1. Create Tree\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Find Parent of a Node\n");
        printf("6. Find Depth of the Tree\n");
        printf("7. Print Ancestors of a Node\n");
        printf("8. Count Leaf Nodes\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Create the binary tree
                printf("Enter the number of nodes: ");
                //scanf("%d", &N);
                //createTree(N);
                root = createNode(5);
                root->leftchild = createNode(7);
                root->leftchild->rightchild= createNode(10);
                root->rightchild = createNode(8);
                root->rightchild->rightchild = createNode(8);
                root->rightchild->leftchild = createNode(2);
                root->leftchild->rightchild->rightchild = createNode(3);
                break;

            case 2:
                // Inorder Traversal
                printf("Inorder Traversal: ");
                IterativeInorder(root);
                break;

            case 3:
                // Preorder Traversal
                printf("Preorder Traversal: ");
                IterativePreorder(root);
                break;

            case 4:
                // Postorder Traversal
                printf("Postorder Traversal: ");
                IterativePostorder(root);
                break;

            case 5:
                // Find Parent of a Node
                printf("Enter the value of the target node: ");
                //scanf("%d", &target);
                target = 7;
                Tptr parent = ParentNode(root, target);
                if (parent) {
                    printf("Parent of %d is %d\n", target, parent->data);
                } else {
                    printf("Node not found\n");
                }
                break;

            case 6:
                // Find Depth of the Tree
                printf("Depth of the tree is: %d\n", treeDepth(root));
                break;

            case 7:
                // Print Ancestors of a Node
                printf("Enter the value of the target node: ");
                //scanf("%d", &target);
                target = 3;
                printf("Ancestors of %d: ", target);
                Ancestors(root,target);
                break;

            case 8:
                // Count Leaf Node
                printf("Number of leaf nodes: %d\n", leafNodes(root));
                break;

            case 9:
                // Exit
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 9);

    return 0;
}
