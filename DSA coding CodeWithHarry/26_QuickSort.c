#include <stdio.h>

void display(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
}

void swap(int *first, int *second)
{
    static int count = 1;
    *first = *first + *second - (*second = *first);
}

int partition(int arr[], int low, int high)
{
    // int piviot = arr[low];
    int piviot = arr[(low+high)/2];// for better average time complexity
    int i = low + 1, j = high;
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
void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(arr, low, high);
        QuickSort(arr, low, partitionIndex - 1);
        QuickSort(arr, partitionIndex + 1, high);
    }
}
int main()
{
    int arr[] = {6, 5, 4, 3, 2, 1};
    int len = sizeof(arr) / sizeof(int);
    printf("Before sorting :\n");
    display(arr, len);
    QuickSort(arr, 0, len - 1);
    printf("\nAfter sorting :\n");
    display(arr, len);
    printf("\n");

    return 0;
}