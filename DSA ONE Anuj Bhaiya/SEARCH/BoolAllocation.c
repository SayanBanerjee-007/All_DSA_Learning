#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int maximum(int arr[], int size)
{
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}
int sum(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}
bool isfeasible(int arr[], int size, int k, int mid)
{
    int student = 1;
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        if ((sum + arr[i]) > mid)
        {
            sum = arr[i];
            student++;
        }
        else
            sum += arr[i];
    }
    if (k >= student)
        return true;
    return false;
}
int minpages(int arr[], int k, int size)
{
    int min = maximum(arr, size);
    int max = sum(arr, size);
    int res = 0;
    while (min <= max)
    {
        int mid = (min + max) / 2;
        if (isfeasible(arr,size, k, mid))
        {
            res = mid;
            max = mid - 1;
        }
        else
        {
            min = mid + 1;
        }
    }
    return res;
}

int main()
{
    int key;
    int arr[] = {10, 5, 20};
    int size = sizeof(arr) / sizeof(int);
    int res = minpages(arr, 2, size);
    printf("minimum number of book allocation -> %d\n", res);

    return 0;
}