// Find number of bits requried to change A to B
#include <stdio.h>

int main()
{
    int A = 6;
    int count = 0;
    int B = 9;
    int mask;
    int xor = A ^ B;
    printf("Xor -> %d \n", xor);

    // Time complexity O(log n)
    /*while (xor)
    {
        mask = 1;
        mask = xor&mask;
        if (mask != 0)
        {
            count++;
        }
        xor >>= 1;
    }*/
    // Time complexity O(1) -> run as same as the number of bits
    while(xor)
    {
        xor = xor & (xor-1);
        count ++;
    }
    printf("count -> %d\n", count);

    return 0;
}