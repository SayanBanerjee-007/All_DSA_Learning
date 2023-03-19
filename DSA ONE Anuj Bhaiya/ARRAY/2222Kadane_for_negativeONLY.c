#include <stdio.h>

int Kadane(int *arr, int size)
{
    int res = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (res < arr[i])    // Hey bro , listen carefully for an array cotaining only negative element the biggest element
            res = arr[i];   // is the largest subarray .So, kadane's algoritham is not usefull here ,LOL !!!     
    }
    return res;
}
int main()
{
    int arr[] = {-5, -4, -6, -3, -4, -1};
    int size = sizeof(arr) / sizeof(int);

    printf("Largest sum of contigious subarray is -> %d\n", Kadane(arr, size));
    return 0;
}