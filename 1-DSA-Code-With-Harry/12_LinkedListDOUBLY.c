#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *previous;
    struct Node *next;
};
void Travarsal(struct Node *head, struct Node *last)
{
    printf("Head to last: \n");
    while (head != NULL)
    {
        printf("Element -> %d\n", head->data);
        head = head->next;
    }
    printf("Last to head: \n");
    while (last != NULL)
    {
        printf("Element -> %d\n", last->data);
        last = last->previous;
    }
}
int main()
{
    struct Node *head, *second, *third, *fourth, *last;
    head = malloc(sizeof(struct Node));
    second = malloc(sizeof(struct Node));
    third = malloc(sizeof(struct Node));
    fourth = malloc(sizeof(struct Node));
    last = malloc(sizeof(struct Node));

    head->previous = NULL;
    head->data = 10;
    head->next = second;

    second->previous = head;
    second->data = 20;
    second->next = third;

    third->previous = second;
    third->data = 30;
    third->next = fourth;

    fourth->previous = third;
    fourth->data = 40;
    fourth->next = last;

    last->previous = fourth;
    last->data = 50;
    last->next = NULL;

    Travarsal(head, last);

    return 0;
}