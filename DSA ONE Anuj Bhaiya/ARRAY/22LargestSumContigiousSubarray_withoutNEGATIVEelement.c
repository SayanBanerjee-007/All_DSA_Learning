#include <stdio.h>

int main()
{
    int arr[] = {2, 4, 6, 2, 4, 2};
    int sum, large_sum = 0;

    int size = sizeof(arr) / sizeof(int);
    for (int i = 0; i < size; i++)
    {
        sum = arr[i];
        for (int j = i + 1; j < size; j++)
        {
            sum += arr[j];// For a array with only positive element largest sum of contigious subarray is the sum of all 
                         //   the element in the array , so using BRUTE FORCE is useless here , LOL !!!
        }
        if (large_sum < sum)
            large_sum = sum;
    }
    printf("Largest sum of contigious subarray is -> %d\n", large_sum);
    return 0;
}