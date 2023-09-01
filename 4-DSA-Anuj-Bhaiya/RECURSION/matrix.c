// Find the number of ways in a matrix i*j to reach a(i,j) from a(0,0)
// condition - only left and bottom movement is allowed
#include <stdio.h>

int ways(int i, int j)
{
    if (i == 1 || j == 1)
    {
        return 1;
    }
    return ways(i - 1, j) + ways(i, j - 1);
}
int main()
{
    int i, j;
    printf("Enter number of row ->  ");
    scanf("%d", &i);
    printf("Enter number of colunm ->  ");
    scanf("%d", &j);

    printf("Number of ways is -> %d\n", ways(i, j));
    return 0;
}