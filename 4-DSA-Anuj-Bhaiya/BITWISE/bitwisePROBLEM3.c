#include <stdio.h>
#include <stdlib.h>

int nonRepeating(int arr[], int len, int k)
{
    int *binary = (int *)calloc((sizeof(int) * 8), sizeof(int));
    int pos = 0, res = 0;
    for (int i = 0; i < len; i++)
    {
        int xor = arr[i];
        pos = 0;
        while (xor != 0)
        {
            if ( xor&1)
            {
                binary[pos]++;
            }
            pos++;
            xor >>= 1;
        }
    }
    for (int i = 0; i <= pos; i++)
    {
        res += (binary[i] % k) * (1 << i);
    }
    return res;
}

int main()
{
    int arr[] = {4, 5, 1, 4, 4, 5, 2, 5, 2, 2};
    int len = sizeof(arr) / sizeof(int);
    int repeating_time = 3;
    int res = nonRepeating(arr, len, repeating_time);

    printf("The non repeted element is -> %d\n", res);
    return 0;
}