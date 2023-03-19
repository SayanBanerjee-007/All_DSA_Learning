#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
void travarsal(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
}
void enqueue(struct Node **f, struct Node **r, int val)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        printf("Queue is full.\n");
        exit(0);
    }
    else
    {
        ptr->data = val;
        ptr->next = NULL;
        if (*f == NULL)
        {
            *f = *r = ptr;
        }
        else
        {
            (*r)->next = ptr;
            *r = ptr;
        }
    }
}
int dequeue(struct Node **f)
{

    if (*f == NULL)
    {
        printf("Queue is empty.\n");
        exit(0);
    }
    else
    {
        struct Node *ptr = *f;
        int temp = (*f)->data;
        (*f) = (*f)->next;
        free(ptr);
        return temp;
    }
}
int main()
{
    struct Node *front = NULL;
    struct Node *rare = NULL;
    enqueue(&front, &rare, 45);
    enqueue(&front, &rare, 425);
    enqueue(&front, &rare, 89);
    travarsal(front);
    dequeue(&front);
    travarsal(front);
    return 0;
}