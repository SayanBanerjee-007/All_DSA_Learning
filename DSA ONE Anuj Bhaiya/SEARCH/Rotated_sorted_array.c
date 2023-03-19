//Search an element in a Sorted & Rotated Array
#include <stdio.h>

int BS_Iteratively_updated(int *arr, int key, int size) // MORE efficient
{
    int low = 0, high = size;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[low] == key)
            return low;
        else if (arr[high] == key)
            return high;
        if (arr[low] < arr[mid])
        {
            if (key >= arr[low] && key < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (key <= arr[high] && key > arr[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}
int BS_Recursively_updated(int *arr, int key, int low, int high) // LESS eficient
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[low] == key)
            return low;
        else if (arr[high] == key)
            return high;
        if (arr[low] < arr[mid])
        {
            if (key >= arr[low] && key < arr[mid])
                return BS_Recursively_updated(arr, key, low, mid - 1);
            else
                return BS_Recursively_updated(arr, key, mid + 1, high);
        }
        else
        {
            if (key <= arr[high] && key > arr[mid])
                return BS_Recursively_updated(arr, key, mid + 1, high);
            else
                return BS_Recursively_updated(arr, key, low, mid - 1);
        }
    }
    return -1;
}
int main()
{
    int key;
    int arr[] = {12, 23, 35, 45, 55, 66, 77, 79, 81, 99, 123, 154, 179, 246, 954, 2, 4, 6, 7, 9};
    int size = sizeof(arr) / sizeof(int);
    printf("Enter the element you want to search: ");
    scanf("%d", &key);

    int index_position11 = BS_Iteratively_updated(arr, key, size - 1);
    printf("Key position -> %d\n", index_position11);
    int index_position22 = BS_Recursively_updated(arr, key, 0, size - 1);
    printf("Key position -> %d\n", index_position22);
    return 0;
}