#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};
int isFull(struct Stack *ptr)
{
    if (ptr->size - 1 == ptr->top)
    {
        return 1;
    }
    return 0;
}
int isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}
void push(struct Stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Stack overflow!!! \nCANNOT PUSH %d TO THE STACK.\n", value);
    }
    else
    {
        ptr->arr[++(ptr->top)] = value;
    }
}
int pop(struct Stack *ptr)
{
    int value;
    if (isEmpty(ptr))
    {
        printf("Stack underflow!!! \nCANNOT POP TO THE STACK.\n");
        return -1;
    }
    else
    {
        value=ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}
int main()
{
    struct Stack *s = malloc(sizeof(struct Stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    printf("Stack has been successfully created.\n");

    push(s,45);
    push(s,65);
    push(s,75);
    push(s,85);
   
    printf("POP element is -> %d\n",pop(s));
    
    return 0;
}