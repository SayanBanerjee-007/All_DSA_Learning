#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void D(int *arr)
{
    for (int i = 0; i < 5; i++)
    {
       arr[i]=12;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n",arr[i]);
    }
}

int main()
{
    //    int arr[5]={4,5,2,3,6};
    int *arr = malloc(5 * sizeof(int));
    int *arrres = malloc(5 * sizeof(int));
    arr[0]=45;
    arr[1]=4444;
    arr[2]=45;
    arr[3]=45;
    arr[4]=45;
   
    D(arr);
    printf("%d\n",arr[0]);
    
    return 0;
}