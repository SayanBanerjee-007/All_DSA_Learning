#include <stdio.h>

int main()
{
    int arr[] = {4, 1, 4, 4, 4, 4, 4, 5, 4, 4, 4, 6, 1, 4, 7, 4, 49, 7, 4, 1, 4, 4, 3, 4, 4};
    int index = 0, count = 1;
    int size = sizeof(arr) / sizeof(int);
    for (int i = 1; i < size; i++)
    {
        if (arr[index] == arr[i])
            count++;
        else
            count--;
        if (count == 0)
        {
            index = i;
            count = 1;
        }
    }
    count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[index] == arr[i])
            count++;
    }
    //if (count > (size / 2))
    printf("Majority element is -> %d which is present %d times.\n", arr[index], count);
    //else
    printf("There is no majority element is present in the array.\n");

    return 0;
}