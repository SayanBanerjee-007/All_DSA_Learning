#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct Stack* ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}
int isFull(struct Stack* ptr)
{
    if (ptr->top == ptr->size-1)
    {
        return 1;
    }
    return 0;
}
int main()
{
    // struct Stack s;
    // s.size=10;
    // s.top=-1;
    // s.arr=malloc(s.size*sizeof(int));
    struct Stack *s=malloc(sizeof(struct Stack));
    s->size = 10;
    s->top = -1;
    s->arr = malloc(s->size * sizeof(int));

    // for (int i = 0; i < 10; i++)
    // {
    //     s->arr[i]=rand();
    //     s->top++;
    // }

    if (isEmpty(s))
    {
        printf("Empty.\n");
    }
    else
    {
        printf("Not empty.\n");
    }
    if (isFull(s))
    {
        printf("Full.\n");
    }
    else
    {
        printf("Not full.\n");
    }

    return 0;
}