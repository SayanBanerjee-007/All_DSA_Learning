#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *createnode(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

int main()
{
    // struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    // p->data = 2;
    // p->left = NULL;
    // p->right = NULL;

    // struct Node *p1 = (struct Node *)malloc(sizeof(struct Node));
    // p1->data = 10;
    // p1->left = NULL;
    // p1->right = NULL;

    // struct Node *p2 = (struct Node *)malloc(sizeof(struct Node));
    // p2->data = 7;
    // p2->left = NULL;
    // p2->right = NULL;

    struct Node *p = createnode(2);
    p->left = createnode(10);
    p->right = createnode(7);

    return 0;
}