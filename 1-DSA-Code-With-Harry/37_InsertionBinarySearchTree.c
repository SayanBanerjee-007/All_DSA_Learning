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
// struct Node *Search(struct Node *root, int key)
// {
//     while (root != NULL)
//     {
//         if (root->data == key)
//         {
//             return root;
//         }
//         else if (root->data > key)
//         {
//             root = root->left;
//         }
//         else
//         {
//             root = root->right;
//         }
//     }
//     return NULL;
// }
void Insertion(struct Node *root, int key)
{
    struct Node *previous = NULL;
    while (root != NULL)
    {
        previous = root;
        if (root->data == key)
        {
            printf("Insertion not possible.\n");
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct Node *ptr = createNode(key);
    if (key < previous->data)
    {
        previous->left = ptr;
    }
    else
    {
        previous->right = ptr;
    }
}
int main()
{
    struct Node *p0 = createNode(8);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(10);
    struct Node *p3 = createNode(1);
    struct Node *p4 = createNode(6);
    struct Node *p6 = createNode(14);
    struct Node *p9 = createNode(4);
    struct Node *p10 = createNode(7);
    struct Node *p13 = createNode(13);

    p0->left = p1;
    p0->right = p2;

    p1->left = p3;
    p1->right = p4;

    p2->right = p6;

    p4->left = p9;
    p4->right = p10;

    p6->left = p13;

    Insertion(p0, 5);

    // struct Node *temp = Search(p0, 10);
    // if (temp != NULL)
    // {
    //     printf("Found -> %d\n", temp->data);
    // }
    // else
    // {
    //     printf("Element not found.\n");
    // }

    printf("%d\n", p9->right->data);
    return 0;
}