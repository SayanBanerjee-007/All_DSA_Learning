#include <stdio.h>

void display(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
}

void InsertionSort(int *arr, int len)
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
        arr[j+1] = key;
    }
}
int main()
{
    int arr[] = {6, 5, 4, 3, 2, 1};
    int len = sizeof(arr) / sizeof(int);
    printf("Before sorting :\n");
    display(arr, len);
    InsertionSort(arr, len);
    printf("\nAfter sorting :\n");
    display(arr, len);
    printf("\n");

    return 0;
}