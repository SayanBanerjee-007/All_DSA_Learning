#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int *arr;
    int front;
    int rear;
    int size;
};
int isFull(struct Queue *obj)
{
    if (obj->size - 1 == obj->rear)
    {
        return 1;
    }
    return 0;
}
int isEmpty(struct Queue *obj)
{
    if (obj->front == obj->rear)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct Queue *obj, int data)
{
    if (isFull(obj))
    {
        printf("Queue is full.\n");
    }
    else
    {
        obj->rear++;
        obj->arr[obj->rear] = data;
    }
}
int dequeue(struct Queue *obj)
{
    if (isEmpty(obj))
    {
        printf("Queue is empty.\n");
        exit(0);
    }
    else
    {
        return obj->arr[++obj->front];
    }
}

int lim = 0;
int main()
{
    // Initializing Queue (Array Implementation)
    struct Queue q;
    q.size = 400;
    q.front = q.rear = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // BFS Implementation
    int node;
    int i = 0;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};
    printf("%d", i);
    visited[i] = 1;
    enqueue(&q, i);
    while (!isEmpty(&q))
    {
        node = dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0)
            {
                printf("\t%d",j);
                visited[j]=1;
                enqueue(&q,j);
            }
        }
    }
    printf("\n");
    return 0;
}