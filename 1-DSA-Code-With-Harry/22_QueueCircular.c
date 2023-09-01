#include <stdio.h>
#include <stdlib.h>

struct QueueCircular
{
    int size;
    int front, rare;
    int *arr;
};
int isEmpty(struct QueueCircular *ptr)
{
    if (ptr->front == ptr->rare)
    {
        return 1;
    }
    return 0;
}
int isFull(struct QueueCircular *ptr)
{
    if ((ptr->rare + 1) % ptr->size == ptr->front)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct QueueCircular *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Queue overflow!!! \n");
    }
    else
    {
        ptr->rare = (ptr->rare + 1) % ptr->size;
        // printf("ptr->rare :  %d \n",ptr->rare);
        ptr->arr[ptr->rare] = value;
    }
}
int dequeue(struct QueueCircular *ptr)
{
    int value;
    if (isEmpty(ptr))
    {
        printf("Queue underflow!!! \n");
        return -1;
    }
    else
    {
        ptr->front = (ptr->front + 1) % ptr->size;
        value = ptr->arr[ptr->front];
        return value;
    }
}
int main()
{
    struct QueueCircular *obj;
    obj->size = 3;
    obj->front = 0;
    obj->rare = 0;
    obj->arr = malloc(obj->size * sizeof(struct QueueCircular));

    printf("isEmpty -> %d\n", isEmpty(obj));
    printf("isFull -> %d\n", isFull(obj));
    enqueue(obj, 45);
    enqueue(obj, 42);
    printf("isEmpty -> %d\n", isEmpty(obj));
    printf("isFull -> %d\n", isFull(obj));
    dequeue(obj);
    dequeue(obj);
    printf("isEmpty -> %d\n", isEmpty(obj));
    printf("isFull -> %d\n", isFull(obj));
    enqueue(obj, 45);
    enqueue(obj, 42);
    printf("isEmpty -> %d\n", isEmpty(obj));
    printf("isFull -> %d\n", isFull(obj));
    return 0;
}