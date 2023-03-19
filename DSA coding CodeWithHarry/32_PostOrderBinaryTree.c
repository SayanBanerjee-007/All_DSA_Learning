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
void PostOrder(struct Node* root)
{
    if(root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ",root->data);
    }
}
int main()
{
    struct Node *p0 = createNode(10);
    struct Node *p1 = createNode(7);
    struct Node *p2 = createNode(5);
    struct Node *p3 = createNode(23);
    struct Node *p4 = createNode(54);

    p0->left = p1;
    p0->right = p2;
    p1->left = p3;
    p1->right = p4;

    PostOrder(p0);

    return 0;
}