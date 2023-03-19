#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *createNode(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}
struct Node *Search(struct Node *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
        {
            return root;
        }
        else if (root->data > key)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}
int main()
{
    struct Node *p0 = createNode(10);
    struct Node *p1 = createNode(7);
    struct Node *p2 = createNode(12);
    struct Node *p3 = createNode(5);
    struct Node *p4 = createNode(9);

    p0->left = p1;
    p0->right = p2;
    p1->left = p3;
    p1->right = p4;

    struct Node *temp = Search(p0, 9);
    if (temp != NULL)
    {
        printf("Found -> %d\n", temp->data);
    }
    else
    {
        printf("Element not found.\n");
    }
    

    return 0;
}