#include <stdio.h>

int Kadane(int *arr, int size)
{
    int current_sum = 0, max_sum = 0;
    for (int i = 0; i < size; i++)
    {
        current_sum += arr[i];
        if (current_sum > max_sum)
            max_sum = current_sum;
        if (current_sum < 0)
            current_sum = 0;
    }
    return max_sum;
}
int main()
{
    int arr[] = {-5, 4, 6, -3, 4, -1};
    int size = sizeof(arr) / sizeof(int);

    printf("Largest sum of contigious subarray is -> %d\n", Kadane(arr,size));
    return 0;
}