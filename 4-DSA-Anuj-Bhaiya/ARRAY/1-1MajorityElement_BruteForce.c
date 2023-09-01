#include <stdio.h>

int main()
{
    int arr[] = {4, 1, 2, 1, 1};
    int count, prev_count = 1, ele;
    int size = sizeof(arr) / sizeof(int);
    for (int i = 0; i < size; i++)
    {
        count = 0;
        for (int j = 0; j < size; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }
        if (prev_count < count)
        {
            prev_count = count;
            ele = arr[i];
        }
    }
    printf("PRE => %d, element -> %d\n", count,ele);
    return 0;
}