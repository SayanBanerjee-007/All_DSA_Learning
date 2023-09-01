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
void InOrder(struct Node *root)
{
    if (root != NULL)
    {
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
    
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
// void Insertion(struct Node *root, int key)
// {
//     struct Node *previous = NULL;
//     while (root != NULL)
//     {
//         previous = root;
//         if (root->data == key)
//         {
//             printf("Insertion not possible.\n");
//             return;
//         }
//         else if (key < root->data)
//         {
//             root = root->left;
//         }
//         else
//         {
//             root = root->right;
//         }
//     }
//     struct Node *ptr = createNode(key);
//     if (key < previous->data)
//     {
//         previous->left = ptr;
//     }
//     else
//     {
//         previous->right = ptr;
//     }
// }
struct Node *InOrderPredecessor(struct Node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
struct Node *Deletion(struct Node *root, int value)
{
    struct Node *inpre;

    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    //Search for the node to be deleted
    if (root->data > value)
    {
        root->left = Deletion(root->left, value);
    }
    else if (root->data < value)
    {
        root->right = Deletion(root->right, value);
    }
    //Deletion straegy when node is found
    else
    {
        inpre = InOrderPredecessor(root);
        root->data = inpre->data;
        root->left = Deletion(root->left, inpre->data);
    }
    return root;
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

    // Insertion(p0, 5);
    // struct Node *temp = Search(p0, 10);
    // if (temp != NULL)
    // {
    //     printf("Found -> %d\n", temp->data);
    // }
    // else
    // {
    //     printf("Element not found.\n");
    // }

    InOrder(p0);
    printf("\n");

    Deletion(p0, 1);
    
    InOrder(p0);
    printf("\n");

    return 0;
}