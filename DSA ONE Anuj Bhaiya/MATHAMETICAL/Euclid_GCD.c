#include <stdio.h>
#include <stdlib.h>

int GCD(int a, int b)
{
    /*if(a%b==0)
    {
        return (b);
    }
    if(a<b)
    {
        return GCD(a,b-a);
    }
    else
    {
        return GCD(b,a-b);
    }*/
    if (a % b == 0)
    {
        return abs(b);
    }
    return GCD(b, a - b);
}
int Euclid_GCD(int a, int b)
{
    // if (a % b == 0)
    //     return (b);
    // return Euclid_GCD(b, a % b);
    return a%b == 0? b: (Euclid_GCD(b,a%b));
}
int main()
{
    int res = Euclid_GCD(270, 132);
    printf("GCD is %d \n", res);
    return 0;
}