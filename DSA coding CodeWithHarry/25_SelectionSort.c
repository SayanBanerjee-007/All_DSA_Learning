#include <stdio.h>

void display(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
     printf("\n");
}
void swap(int *first, int *second)
{
    static int count = 1;
    *first = *first + *second - (*second = *first);
    // printf("\nSwap -> %d\n", count++);
}
void SelectionSort(int *arr, int len)
{
    int indexofmin, j;
    for (int i = 0; i < len - 1; i++)
    {
        indexofmin = i;
        for (j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[indexofmin])
            {
                indexofmin = j;
            }
        }
        swap(&arr[indexofmin], &arr[i]);
        display(arr, len);
    }
}
int main()
{
    int arr[] = {4, 2, 3, 9, 7, 5, 1, 0};
    int len = sizeof(arr) / sizeof(int);
    printf("Before sorting :\n");
    display(arr, len);
    SelectionSort(arr, len);
    printf("After sorting :\n");
    display(arr, len);

    return 0;
}