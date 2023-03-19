#include <stdio.h>
#include <stdlib.h>

struct LinkedList
{
    int data;
    struct LinkedList *next;
};
void Travarsal(struct LinkedList *head)
{
    while (head != NULL)
    {
        printf("Value is %d\n", head->data);
        head = head->next;
    }
}
struct LinkedList *FirstInsertion(struct LinkedList *head, int data)
{
    struct LinkedList *ptr = malloc(sizeof(struct LinkedList));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}
void BetweenInsertion(struct LinkedList *head, int index, int data)
{
    int i = 1;
    while (i < index - 1)
    {
        head = head->next;
        i++;
    }
    struct LinkedList *ptr = malloc(sizeof(struct LinkedList));
    ptr->data = data;
    ptr->next = head->next;
    head->next = ptr;
}
void LastInsertion(struct LinkedList *head, int data)
{
    while (head->next != NULL)
    {
        head = head->next;
    }
    struct LinkedList *ptr = malloc(sizeof(struct LinkedList));
    ptr->data = data;
    ptr->next = head->next;
    head->next = ptr;
}
struct LinkedList *FirstDeletion(struct LinkedList **head)
{
    struct LinkedList ***ptr = &head;
    (*head) = (*head)->next;
    free(*ptr);
    return (*head);
}
void BetweenDeletion(struct LinkedList **head, int index)
{
    int i = 1;
    while (i < index - 1)
    {
        *head = (*head)->next;
        i++;
    }
    struct LinkedList ***ptr = &head;
}
int main()
{
    struct LinkedList *head, *second, *third, *fourth, *fifth, *last;

    head = malloc(sizeof(struct LinkedList));
    second = malloc(sizeof(struct LinkedList));
    third = malloc(sizeof(struct LinkedList));
    fourth = malloc(sizeof(struct LinkedList));
    fifth = malloc(sizeof(struct LinkedList));
    last = malloc(sizeof(struct LinkedList));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = fifth;

    fifth->data = 50;
    fifth->next = last;

    last->data = 60;
    last->next = NULL;

    // Travarsal(head);
    // head = FirstInsertion(head, 0);
    // Travarsal(head);
    // BetweenInsertion(head, 2, 5);
    // Travarsal(head);
    // LastInsertion(head, 70);
    // Travarsal(head);

    head = FirstDeletion(&head);
    Travarsal(head);
    // BetweenDeletion(&head,2);
    // Travarsal(head);

    return 0;
}