#include <stdio.h>

int fastPower(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        // res = res * a;   // time complexity O(b)
        // b--;

        if (b & 1) // if odd
        {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}
long Modulo(long a, long b, int n)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1) // if odd
        {
            res = (res * a % n) % n;
        }
        a = (a % n * a % n) % n;
        b >>= 1;
    }
    return res;
}

int main()
{
    printf("3^5 = %d\n", fastPower(3, 5));
    printf("3^5 = %d\n", Modulo(3978432, 5, 10000007));
    return 0;
}