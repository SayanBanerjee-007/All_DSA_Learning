// number of zeros in the end of a factorial of a number
#include<stdio.h>

int main()
{
    int num,res= 0;
    printf("Enter a number: ");
    scanf("%d",&num);
    for (int i = 5; i <= num; i*=5)
    {
        res += num/i; 
    }
    
    printf("Number of zeros in the end of %d! is -> %d\n",num,res);

    return 0;
}