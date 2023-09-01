// Best time to buy and sell stock to Maximise Profit
// Time complexity O(n^2)
#include <stdio.h>

int main()
{
    int arr[] = {3, 1, 4, 8, 7, 2, 5};
    int size = sizeof(arr) / sizeof(int);
    int max_profit = 0, cur_profit = 0, res;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            res = arr[i] - arr[j];
            if (res > cur_profit)
                cur_profit = res;
        }
        if (cur_profit > max_profit)
            max_profit = cur_profit;
    }
    printf("Max profit is %d\n",max_profit);
    return 0;
}