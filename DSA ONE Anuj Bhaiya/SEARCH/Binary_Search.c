#include <stdio.h>
#include <stdbool.h>

bool BS_recursion(int *arr, int l, int h, int key)
{
    if (l <= h)
    {
        int mid = (l + h) / 2;
        if (arr[l] == key || arr[h] == key || arr[mid] == key)
            return true;
        if (key < arr[mid])
            return BS_recursion(arr, l, mid - 1, key);
        if (key > arr[mid])
            return BS_recursion(arr, mid + 1, h, key);
    }
    return false;
}
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
int main()
{
    int key;
    int arr[] = {2, 4, 6, 7, 9, 12, 23, 35, 45, 55, 66, 77, 79, 81, 99, 123, 154, 179, 246, 954};
    int size = sizeof(arr) / sizeof(int);
    printf("Enter the element you want to search: ");
    scanf("%d", &key);

    if (BS_recursion(arr, 0, size - 1, key))
        printf("Element is found.\n");
    else
        printf("Element is not Ffound.\n");

    if (BS_iteratively(arr, 0, size - 1, key))
        printf("Element is found.\n");
    else
        printf("Element is not Ffound.\n");

    return 0;
}