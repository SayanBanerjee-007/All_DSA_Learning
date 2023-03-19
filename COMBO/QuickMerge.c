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
int partition(int *arr, int low, int high)
{
    int i = low + 1, j = high, piviot = arr[low];
    do
    {
        while (arr[i] < piviot)
        {
            i++;
        }
        while (arr[j] > piviot)
        {
            j--;
        }
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }

    } while (i < j);
    swap(&arr[low], &arr[j]);
    return j;
}
void Merge(int *arr, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    // int *copy = malloc((high + 1) * sizeof(int));
    int copy[100];
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            copy[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            copy[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        copy[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        copy[k] = arr[j];
        j++;
        k++;
    }
    for (int num = 0; num <= high; num++)
    {
        arr[num] = copy[num];
    }
}
void Quicksort(int *arr, int low, int high)
{
    int partitionIndex;
    if (low < high)
    {
        partitionIndex = partition(arr, low, high);
        Quicksort(arr, low, partitionIndex - 1);
        Quicksort(arr, partitionIndex + 1, high);
    }
}
void MS(int *arr, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        MS(arr, low, mid);
        MS(arr, mid + 1, high);
        Merge(arr, low, mid, high);
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(int);

    printf("Before sorting: \n");
    display(arr, len);
    // Quicksort(arr, 0, len - 1);
    MS(arr, 0, len - 1);
    printf("After sorting: \n");
    display(arr, len);

    return 0;
}