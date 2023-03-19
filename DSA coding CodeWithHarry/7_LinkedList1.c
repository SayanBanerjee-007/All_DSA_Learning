#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
void Travarsal(struct Node* ptr)
{
    while(ptr!=NULL)
    {
        printf("Element -> %d\n",ptr->data);
        ptr=ptr->next;
    }
}
int main()
{
    struct Node *head,*second,*third,*last;  
    head=malloc(sizeof(struct Node));
    second=malloc(sizeof(struct Node));
    third=malloc(sizeof(struct Node));
    last=malloc(sizeof(struct Node));

    // Allocate head to second
    head->data=5;
    head->next=second;

    second->data=10;
    second->next=third;

    third->data=15;
    third->next=last;

    last->data=20;
    last->next=NULL;

    Travarsal(head);
    return 0;
}