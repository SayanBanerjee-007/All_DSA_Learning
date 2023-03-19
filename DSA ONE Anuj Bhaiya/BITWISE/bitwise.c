#include <stdio.h>

int main()
{
    // ~ use
    int a = 5;
    printf("primarily -> %d\n", a);
    a = ~a;
    printf("After 2s complement(~) a -> %d\n", a);// output 2s complement = a 1s complement
    // >> use
    int b = 6;
    printf("primarily -> %d\n", b);
    b= b>>1;
    printf("After right shift(>>) b -> %d\n",b);
    b = b<<1;
    printf("After left shift(<<) b -> %d\n",b);

    return 0;
}