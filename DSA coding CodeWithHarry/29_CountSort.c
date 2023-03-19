#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void display(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
}
int maxofarray(int *arr, int len)
{
    int max = INT_MIN;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
void CountSort(int *arr, int len)
{
    int i, j;
    int max = maxofarray(arr, len);
    int *count = (int *)malloc((max + 1) * sizeof(int));
    for (i = 0; i < max+1; i++)
    {
        count[i] = 0;
    }
    for (i = 0; i < len; i++)
    {
        if (arr[i] >= 0)
        {
            count[arr[i]]++;
        }
    }
    i = j = 0;
    while (i <= max)
    {
        if (count[i] > 0)
        {
            arr[j] = i;
            count[i]--;
            j++;
        }
        else
        {
            i++;
        }
    }
}
int main()
{
    int arr[] = {6, 5, 4, 3, 2, 1,0};
    int len = sizeof(arr) / sizeof(int);
    printf("Before sorting :\n");
    display(arr, len);
    CountSort(arr, len);
    printf("\nAfter sorting :\n");
    display(arr, len);
    printf("\n");

    return 0;
}