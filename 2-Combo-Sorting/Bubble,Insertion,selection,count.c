#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void display(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void swap(int *first, int *second)
{
    *first = *first + *second - (*second = *first);
}
int Largest(int *arr, int len)
{
    int max = INT_MIN;
    for (int i = 0; i < len; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}
void Bubblesort(int *arr, int len)
{
    int issorted;
    for (int i = 0; i < len - 1; i++)
    {
        issorted = 1;
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                issorted = 0;
            }
        }
        // display(arr, len);
        if (issorted)
        {
            break;
        }
    }
}
void Insertionsort(int *arr, int len)
{
    int key, j;
    for (int i = 1; i < len; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        // display(arr, len);
    }
}
void Selectionsort(int *arr, int len)
{
    int indexposition;
    for (int i = 0; i < len - 1; i++)
    {
        indexposition = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[indexposition] > arr[j])
            {
                indexposition = j;
            }
        }
        swap(&arr[i], &arr[indexposition]);
        // display(arr, len);
    }
}
void Countsort(int *arr, int len)
{
    int size = Largest(arr, len) + 1;
    int i, j;
    int *ptr = (int *)malloc(size * sizeof(int));
    for (i = 0; i < size; i++)
    {
        ptr[i] = 0;
    }
    for (i = 0; i < len; i++)
    {
        ptr[arr[i]]++;
    }
    i = j = 0;
    while (j < size)
    {
        if (ptr[j] > 0)
        {
            arr[i] = j;
            ptr[j]--;
            i++;
        }
        else
        {
            j++;
        }
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(int);

    printf("Before sorting: \n");
    display(arr, len);
    // Bubblesort(arr, len);
    // Insertionsort(arr, len);
    // Selectionsort(arr, len);
    Countsort(arr, len);
    printf("After sorting: \n");
    display(arr, len);
    return 0;
}