#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front, rare;
    int *arr;
};
int isEmpty(struct Queue *ptr)
{
    if (ptr->front == ptr->rare)
    {
        return 1;
    }
    return 0;
}
int isFull(struct Queue *ptr)
{
    if (ptr->rare + 1 == ptr->size)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct Queue *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Queue overflow!!! \n");
    }
    else
    {
        ptr->arr[++ptr->rare] = value;
    }
}
int dequeue(struct Queue *ptr)
{
    int value;
    if (isEmpty(ptr))
    {
        printf("Queue underflow!!! \n");
        return -1;
    }
    else
    {
        value = ptr->arr[++ptr->front];
        return value;
    }
}
int main()
{
    struct Queue *obj;
    obj->size = 2;
    obj->front = -1;
    obj->rare = -1;
    obj->arr = malloc(obj->size * sizeof(struct Queue));

    printf("isEmpty -> %d\n", isEmpty(obj));
    printf("isFull -> %d\n", isFull(obj));
    enqueue(obj, 45);
    enqueue(obj, 42);
    printf("isEmpty -> %d\n", isEmpty(obj));
    printf("isFull -> %d\n", isFull(obj));
    return 0;
}