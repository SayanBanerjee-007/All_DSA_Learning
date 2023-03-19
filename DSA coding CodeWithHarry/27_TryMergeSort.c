#include <stdio.h>
#include <stdlib.h>

void display(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
}

void MergeSort(int *arr1, int *arr2, int *arrRes, int len1, int len2)
{
    int i = 0, j = 0, k = 0;
    while (k < (len1 + len2))
    {
        if (arr1[i] <= arr2[j] && i < len1)
        {
            arrRes[k] = arr1[i];
            i++;
            k++;
            if (i == len1)
            {
                goto jump1;
            }
        }
        else if (arr1[i] > arr2[j] && j < len2)
        {
            arrRes[k] = arr2[j];
            j++;
            k++;
            if (j == len2)
            {
                goto jump2;
            }
        }
    }
jump1:
    while (j < len2)
    {
        arrRes[k] = arr2[j];
        j++;
        k++;
    }
    exit(0);
jump2:
    while (i < len1)
    {
        arrRes[k] = arr1[i];
        i++;
        k++;
    }
}
int main()
{
    int arr1[] = {12, 34, 56, 94 ,100 ,750};
    int arr2[] = {1, 5, 12, 45};
    int len1 = sizeof(arr1) / sizeof(int);
    int len2 = sizeof(arr2) / sizeof(int);
    int *arrRes = malloc((len1 + len2) * sizeof(int));
    MergeSort(arr1, arr2, arrRes, len1, len2);

    printf("Before sorting :\n");
    display(arr1, len1);
    printf("\n");
    display(arr2, len2);

    printf("\nAfter sorting :\n");
    display(arrRes, len1 + len2);
    printf("\n");

    return 0;
}