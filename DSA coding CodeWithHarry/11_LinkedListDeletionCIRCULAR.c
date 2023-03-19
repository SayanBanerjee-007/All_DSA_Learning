#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Travarsal(struct Node *ptr)
{
    struct Node *head = ptr;
    do
    {
        printf("Element -> %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}
struct Node *FirstDeletion(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
void BetweenDeleteion(struct Node *head, int index)
{
    struct Node *ptr = head;
    struct Node *ptrdelete;
    int i = 0;
    while (i < index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    ptrdelete = ptr->next;
    ptr->next = ptrdelete->next;
    free(ptrdelete);
}
struct Node *LastDeletion(struct Node *head)
{
    struct Node *ptr = head;
    while ((ptr->next)->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = head;
    free(ptr->next);
    return ptr;
}
struct Node *NodeDeletion(struct Node *head, struct Node *delete)
{
    struct Node *ptr = head;
    if (head == delete)
    {
        head = head->next;
        free(ptr);
        return head;
    }
    else
    {
        if (ptr->next == delete)
        {
            ptr->next = delete->next;
            free(delete);
            return head;
        }
        else if ((ptr->next)->next == delete)
        {
            ptr = ptr->next;
            ptr->next = delete->next;
            free(ptr);
            return head;
        }
        else
        {
            while ((ptr->next)->next != delete)
            {
                ptr = ptr->next;
            }
            free(ptr);
            return head;
        }
    }
}

int main()
{
    struct Node *head, *second, *third, *fourth, *fifth, *last;
    head = malloc(sizeof(struct Node));
    second = malloc(sizeof(struct Node));
    third = malloc(sizeof(struct Node));
    fourth = malloc(sizeof(struct Node));
    fifth = malloc(sizeof(struct Node));
    last = malloc(sizeof(struct Node));

    head->data = 11;
    head->next = second;
    second->data = 22;
    second->next = third;
    third->data = 33;
    third->next = fourth;
    fourth->data = 44;
    fourth->next = fifth;
    fifth->data = 55;
    fifth->next = last;
    last->data = 66;
    last->next = head;

    Travarsal(head);

    printf("First Deletion: \n");
    head = FirstDeletion(head);
    last->next = head;
    Travarsal(head);

    printf("Between Deletion: \n");
    BetweenDeleteion(head, 1);
    Travarsal(head);

    printf("Last Deletion: \n");
    last = LastDeletion(head);
    Travarsal(head);

    printf("Node Deletion: \n");
    head = NodeDeletion(head, second);
    last->next = head;
    Travarsal(head);

    return 0;
}