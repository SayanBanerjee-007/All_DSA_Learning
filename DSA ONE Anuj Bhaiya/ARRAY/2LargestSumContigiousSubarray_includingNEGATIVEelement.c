#include <stdio.h>

int main()
{
    int arr[] = {-5, 4, 6, -3, 4, -1};
    int sum_in = 0, sum_out = 0, large_sum = 0;

    int size = sizeof(arr) / sizeof(int);
    for (int i = 0; i < size; i++)
    {
        sum_in = 0;
        for (int j = i; j < size; j++)
        {
            sum_in += arr[j];
            if (sum_out < sum_in)
                sum_out = sum_in;
        }
        if (large_sum < sum_out)
            large_sum = sum_out;
    }
    printf("Largest sum of contigious subarray is -> %d\n", large_sum);
    return 0;
}