#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
void Travarsal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element -> %d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct Node *FirstInsertion(struct Node *head, int data)
{
    struct Node *ptr = malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}
void *InsertionBetween(struct Node *head, int index, int data)
{
    int i = 0;
    struct Node *ptr = malloc(sizeof(struct Node));
    struct Node *p = head;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    ptr->data = data;
    p->next = ptr;
}
void LastInsertion(struct Node *head,int data)
{
    struct Node *ptr = malloc(sizeof(struct Node));
    struct Node *p= head;
    while(p->next!= NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->data= data;
    ptr->next=NULL;
}
void NodeInsertion(struct Node *previous_node,int data)
{
    struct Node *ptr = malloc(sizeof(struct Node));
    ptr->data= data;
    ptr->next=previous_node->next;
    previous_node->next= ptr;
}
int main()
{
    struct Node *head, *second, *third, *last;
    head = malloc(sizeof(struct Node));
    second = malloc(sizeof(struct Node));
    third = malloc(sizeof(struct Node));
    last = malloc(sizeof(struct Node));

    // Allocate head to second
    head->data = 5;
    head->next = second;

    second->data = 10;
    second->next = third;

    third->data = 15;
    third->next = last;

    last->data = 20;
    last->next = NULL;
    printf("Real: \n");
    Travarsal(head);

    printf("Insertion at first: \n");
    head = FirstInsertion(head, 0);
    Travarsal(head);

    printf("Insertoin Between: \n");
    InsertionBetween(head, 1, 157);
    Travarsal(head);

    printf("Insertion at end: \n");
    LastInsertion(head,555);
    Travarsal(head);

    printf("Insertion at any node: \n");
    NodeInsertion(second,7594);
    Travarsal(head);
    return 0;
}