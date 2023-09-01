#include <stdio.h>
#include <stdlib.h>

struct stackLinkedList
{
    int data;
    struct stackLinkedList *next;
};
void Travarsal(struct stackLinkedList *ptr)
{
    while (ptr != NULL)
    {
        printf("Element -> %d\n", ptr->data);
        ptr = ptr->next;
    }
}
int isEmpty(struct stackLinkedList *top)
{
    if (top->next == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stackLinkedList *top)
{
    struct stackLinkedList *n = malloc(sizeof(struct stackLinkedList));
    if (n == NULL)
    {
        return 1;
    }
    else
    {
        free(n);
        return 0;
    }
}
struct stackLinkedList *push(struct stackLinkedList *top, int data)
{
    if (isFull(top))
    {
        printf("Stack Overflow.\n");
        exit(0);
    }
    else
    {
        struct stackLinkedList *new = malloc(sizeof(struct stackLinkedList));
        new->data = data;
        new->next = top;
        top = new;
        return top;
    }
}

int pop (struct stackLinkedList **top)
{
    if (isFull(*top))
    {
        printf("Stack Underflow.\n");
        exit(0);
    }
    else
    {
        int value = (*top)->data;
        struct stackLinkedList *temp =*top;
        *top=(*top)->next;
        free(temp);
        return value;
    }
}
int main()
{
    struct stackLinkedList *top = NULL;
    top = push(top, 45);
    top = push(top, 25);
    top = push(top, 75);
    Travarsal(top);
    printf("Pop value is-> %d\n",pop(&top));

    return 0;
}