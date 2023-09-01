// Stock Buy & Sell to Maximise Profit - 2
#include <stdio.h>

int main()
{
    int arr[] = {5, 2, 6, 1, 4, 7, 3, 6};
    int size = sizeof(arr) / sizeof(int);
    int profit = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > arr[i - 1])
            profit += arr[i] - arr[i - 1];
    }

    printf("Max profit is %d\n", profit);
    return 0;
}