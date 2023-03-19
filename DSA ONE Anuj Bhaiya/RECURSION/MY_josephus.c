#include <stdio.h>
#include <stdlib.h>

int *array(int *arr, int size, int kill_pos)
{
    int i = 0, j;
    int *cpy = (int *)malloc(size * sizeof(int));
    for (i = 0, j = kill_pos + 1; j < size; i++, j++)
    {
        cpy[i] = arr[j];
    }
    for (i, j = 0; j < kill_pos; i++, j++)
    {
        cpy[i] = arr[j];
    }
    return cpy;
}
int main()
{
    int size, k = 3,pos,gun,kill_pos;
    printf("Enter size -> ");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        arr[i] = i;
    }

    while (size != 1)
    {
        // for (int i = 0; i < size; i++)
        // {
        //     printf("%d\t", arr[i]);
        // }
        // printf("gun-> %d\t size-> %d\n",gun,size);
        pos = 3 % size;
        gun = arr[pos];
        for (int i = 0; i < size; i++)
        {
            kill_pos = i - 1;
            if (arr[i] == gun)
                break;
        }
        arr = array(arr, size, kill_pos);
        size--;
    }
    printf("Winer -> %d\n", gun);
    return 0;
}