#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool *SieveofEratosthenes(int n)
{
    bool *isPrime = malloc((n + 1) * sizeof(bool));
    for (int i = 0; i <= n; i++)
    {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        for (int j = i * 2; j <= n; j += i)
        {
            isPrime[j] = false;
        }
    }
    return isPrime;
}
int main()
{
    bool *isPrime = SieveofEratosthenes(20);
    for (int i = 0; i <= 20; i++)
    {
        printf("%d -> %d\n", i, isPrime[i]);
    }

    return 0;
}