// Time complexity is O(log n)
#include <stdio.h>
#include <stdbool.h>

bool BS_iteratively(int *arr, int l, int h, int key)
{
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (arr[l] == key || arr[h] == key || arr[mid] == key)
            return true;
        if (key < arr[mid])
            h = mid - 1;
        if (key > arr[mid])
            l = mid + 1;
    }
    return false;
}
bool infinite(int *arr, int key)
{
    int low = 0, high = 1;
    while (key > arr[high])
    {
        low = high;
        high *= 2;
    }
    return BS_iteratively(arr, low, high, key);
}
int main()
{
    int key;
    int arr[] = {2, 4, 6, 7, 9, 12, 23, 35, 45, 55, 66, 77, 79, 81, 99, 123, 154, 179, 246, 954};
    int size = sizeof(arr) / sizeof(int);
    printf("Enter the element you want to search: ");
    scanf("%d", &key);

    if (infinite(arr, key))
        printf("Element is found.\n");
    else
        printf("Element is not Ffound.\n");

    return 0;
}