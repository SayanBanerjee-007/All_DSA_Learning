#include <stdio.h>
#include <stdlib.h>

int small(int a, int b)
{
    return a < b ? a : b;
}
int main()
{
    int arr[] = {3, 1, 2, 4, 0, 1, 3, 2};
    int size = sizeof(arr) / sizeof(int);
    int *right = (int *)malloc(size * sizeof(int));
    int *left = (int *)malloc(size * sizeof(int));

    int trap = 0, big_left = arr[0], big_right = arr[size - 1];
    left[0] = arr[0];
    right[size - 1] = arr[size - 1];

    for (int i = 1; i < size; i++)
    {
        if (left[i - 1] < arr[i])
            left[i] = arr[i];
        else
            left[i] = left[i - 1];
    }
    for (int i = size - 2; i >= 0; i--)
    {
        if (right[i + 1] < arr[i])
            right[i] = arr[i];
        else
            right[i] = right[i + 1];
    }
    for (int i = 0; i < size; i++)
    {
        trap += (arr[i] - small(left[i], right[i]));
    }
    printf("Total water trap is -> %d\n", trap);

    return 0;
}