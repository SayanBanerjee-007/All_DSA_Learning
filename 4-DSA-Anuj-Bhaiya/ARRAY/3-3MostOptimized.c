// Best time to buy and sell stock to Maximise Profit
// Time complexity O(n) and space complexity O(1)
#include <stdio.h>

int main()
{
    int arr[] = {3, 1, 4, 8, 7, 2, 5};
    int size = sizeof(arr) / sizeof(int);
    int max_profit = 0, cur_profit, min_so_far = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min_so_far)
            min_so_far = arr[i];
        cur_profit = arr[i] - min_so_far;
        if (max_profit < cur_profit)
            max_profit = cur_profit;
    }
    printf("Max profit is %d\n", max_profit);
    return 0;
}