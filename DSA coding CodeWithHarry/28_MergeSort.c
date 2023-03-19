#include <stdio.h>
#include <stdlib.h>

void display(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
}

void Merge(int *arr, int low, int mid, int high)
{
    int i, j, k, copy[100];
    i = low, j = mid + 1, k = low;
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
void MS(int *arr, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        MS(arr, low, mid);
        MS(arr, mid+1, high);
        Merge(arr, low, mid, high);
    }
}
int main()
{
    int arr[] = {12, 34, 13, 22, 25, 29};
    int len = sizeof(arr) / sizeof(int);

    printf("Before sorting :\n");
    display(arr, len);

    MS(arr, 0, len - 1);
    printf("\nAfter sorting :\n");
    display(arr, len);
    printf("\n");

    return 0;
}