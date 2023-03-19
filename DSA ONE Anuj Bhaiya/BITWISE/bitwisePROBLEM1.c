// Find the only non repeating in an array where every element repeat twice.
#include <stdio.h>

int main()
{
    int arr[9] = {4, 2, 5, 4, 3, 2, 7, 7, 3};
    int res = 0, i = 0;
    while (i < 9)
    {
        res = res ^ arr[i];
        i++;
    }
    printf("The non repeted element is -> %d\n", res);
    return 0;
}