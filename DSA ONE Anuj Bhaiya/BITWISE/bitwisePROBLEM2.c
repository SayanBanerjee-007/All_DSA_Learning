// Find the two non repeating in an array where every element repeat twice.
#include <stdio.h>
#include <stdlib.h>

void nonRepeating(int arr[], int len, int *a, int *b)
{
    int res = 0;
    for (int i = 0; i < len; i++)
    {
        res = res ^ arr[i];
    }
    printf("res -> %d\n", res);
    int set_bit_no = res & (-res);
    printf("set_bit_no -> %d\n", set_bit_no);
    for (int i = 0; i < len; i++)
    {
        if (arr[i] & set_bit_no)
        {
            printf("val in if -> %d\n",(arr[i] & set_bit_no));
            *a = *a ^ arr[i];
            printf("a -> %d\n\n", *a);
        }
        else
        {
            printf("val in else -> %d\n",(arr[i] & set_bit_no));
            *b = *b ^ arr[i];
            printf("b -> %d\n\n", *b);
        }
    }
}
int main()
{
    int arr[] = {4, 5, 4, 1, 1, 12, 9, 8, 9, 8};
    // int *a = (int *)calloc(1, sizeof(int));
    // int *b = (int *)calloc(1, sizeof(int));
    int a=0,b=0;
    int len = sizeof(arr) / sizeof(int);
    nonRepeating(arr, len, &a, &b);

    printf("The non repeted element are -> %d  and %d\n", a, b);
    return 0;
}