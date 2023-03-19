#include <stdio.h>

void swap(int *first, int *second)
{
    *first = *first + *second - (*second = *first);
}
void BubbleSort(int *arr, int len)
{
    int issorted = 0;
    for (int i = 0; i < len - 1; i++)
    {
        issorted = 1;
        // printf("Pass number -> %d\n", i);
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                issorted = 0;
            }
        }
        if (issorted)
        {
            break;
        }
    }
}
int main()
{
    int arr[] = {1,2,3,4,6,5};
    int len = sizeof(arr) / sizeof(int);
    printf("Before sorting :\n");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nAfter sorting :\n");
    BubbleSort(arr, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}