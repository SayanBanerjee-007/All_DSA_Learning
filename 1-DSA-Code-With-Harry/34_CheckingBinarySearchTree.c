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
int isBST(struct Node *root)
{
    static struct Node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && prev->data >= root->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
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

    printf("%d\n", isBST(p0));

    return 0;
}