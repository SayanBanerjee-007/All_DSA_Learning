// Best time to buy and sell stock to Maximise Profit
// Time complexity O(n) but space complexity O(n)
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[] = {3, 1, 4, 8, 7, 2, 5};
    int size = sizeof(arr) / sizeof(int);
    int *max_from_left = (int *)malloc(size * sizeof(int));
    int max_profit = 0, cur_profit;

    max_from_left[size-1] = arr[size-1];
   
    for (int i = size - 2; i >= 0; i--)
    {
        if (arr[i] > max_from_left[i + 1])
            max_from_left[i] = arr[i];
        else
            max_from_left[i] = max_from_left[i + 1];
    }
    for (int i = 0; i < size; i++)
    {
        cur_profit = max_from_left[i] - arr[i];
        if (cur_profit > max_profit)
            max_profit = cur_profit;
    }
  
    printf("Max profit is %d\n", max_profit);
    return 0;
}