#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *right;
    struct Node *left;
    int height;
};
int getheight(struct Node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}
struct Node *createNode(int key)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->key = key;
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->height = 1;
    return ptr;
}
int getBalenceFactor(struct Node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return (getheight(n->right) - getheight(n->left));
}
int max(int left, int right)
{
    if (left > right)
    {
        return left;
    }
    return right;
}
struct Node *rightRotation(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // y->left = x->right;
    x->right = y;
    y->left = T2;

    y->height = max(getheight(y->left), getheight(y->right)) + 1;
    x->height = max(getheight(x->left), getheight(x->right)) + 1;

    return x;
}
struct Node *leftRotation(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // x->right = y->left;
    y->left = x;
    x->right = T2;

    y->height = max(getheight(y->left), getheight(y->right)) + 1;
    x->height = max(getheight(x->left), getheight(x->right)) + 1;

    return y;
}
struct Node *insert(struct Node *n, int key)
{
    if (n == NULL)
    {
        return createNode(key);
    }
    if (key < n->key)
    {
        n->left = insert(n->left, key);
    }
    else if (key > n->key)
    {
        n->right = insert(n->right, key);
    }

    n->height = max(getheight(n->left), getheight(n->right)) + 1;
    int bf = getBalenceFactor(n);
    //Left Left
    if (bf < -1 && key < n->left->key)
    {
        return rightRotation(n);
    }
    //Right Right
    if (bf > 1 && key > n->right->key)
    {
        return leftRotation(n);
    }
    //Left Right
    if (bf < -1 && key > n->left->key)
    {
        n->left = leftRotation(n->left);
        return rightRotation(n);
    }
    //Right Left
    if (bf > 1 && key < n->right->key)
    {
        n->right = rightRotation(n->left);
        return leftRotation(n);
    }

    return n;
}
void preorderTravarsal(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorderTravarsal(root->left);
        preorderTravarsal(root->right);
    }
}
// struct Node *Search(struct Node *root, int key)
// {
//     while (root != NULL)
//     {
//         if (root->key == key)
//         {
//             return root;
//         }
//         else if (root->key > key)
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
int main()
{
    struct Node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    preorderTravarsal(root);
    // struct Node * lol = Search(root,6);
    // printf("\n%d   ",lol->height);
    return 0;
}