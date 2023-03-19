#include <stdio.h>

int main()
{
    // Find a bit by its position
    int num = 12;                 // -> 1100
    int bitposition = 3;          // -> position starts from 0,
    int mask = 1 << bitposition;  // 1 << 3 -> 0001 to 1000
    int res = num & mask;         // 1100 & 1000 -> 1000 -> 8
    printf("res - > %d \n", res); // if res == 0 , the bit at the position is zero ,else one.

    //set a bit(which is bassically to set 1 ) at a given position
    int num2 = 12;                       // -> 1100
    int bitposition2 = 1;                // -> position starts from 0
    int mask2 = 1 << bitposition2;       // 1<< 1 -> 0001 to 0010
    printf("before num2 -> %d\n", num2); // 12
    num2 = num2 | mask2;                 //1100 | 0010 -> 1110
    printf("after num2 -> %d\n", num2);  // 14

    // clear a bit(which is bassically to set 0) at given position
    int num3 = 12;                       // -> 1100
    int bitposition3 = 2;                // -> position starts from 0
    int mask3 = ~(1 << bitposition2);    // ~(1<< 1 -> 0001 to 0010) = 1101
    printf("before num2 -> %d\n", num3); // 12
    num3 = num3 | mask3;                 //1100 & 1011 -> 1000
    printf("after num2 -> %d\n", num3);  // 8

    return 0;
}