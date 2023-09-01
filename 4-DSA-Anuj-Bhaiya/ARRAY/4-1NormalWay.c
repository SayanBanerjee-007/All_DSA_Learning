// Stock Buy & Sell to Maximise Profit - 2
#include <stdio.h>

int main()
{
    int arr[] = {5, 2, 6, 1, 4, 7, 3, 6};
    int size = sizeof(arr) / sizeof(int);
    int peek, bottom, profit, f1 = 0, f2 = 0;
    for (int i = 0; i < size; i++)
    {
        if (i == 0 && arr[i] < arr[i + 1])
        {
            bottom = arr[i];
            f1 = 1;
            printf("bottom-> %d and i->%d \n",bottom,i);
        }
         if (i == size-1 && arr[i] > arr[i - 1])
        {
            peek = arr[i];
            f2 = 1;
            printf("peek -> %d and i->%d \n",peek,i);
        }
        if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1] && f1 == 0)
        {
            bottom = arr[i];
            f1 = 1;
            printf("bottom-> %d and i->%d \n",bottom,i);
        }
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1] && f1 == 1 && f2 == 0)
        {
            peek = arr[i];
            f2 = 1;
            printf("peek -> %d and i->%d \n",peek,i);
        }
        if (f1 == 1 && f2 == 1)
        {
            profit += peek - bottom;
            f1 = f2 = 0;
        }
    }

    printf("Max profit is %d\n", profit);
    return 0;
}