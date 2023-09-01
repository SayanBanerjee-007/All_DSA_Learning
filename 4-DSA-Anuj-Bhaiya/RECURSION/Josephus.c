#include <stdio.h>

int JS(int n, int k)
{
    if (n == 1)
        return 0;
    return ((JS((n - 1), k)) + 3) % n;
}
int main()
{
    int num;
    int k = 3;
    printf("Enter number: ");
    scanf("%d", &num);
    printf("Winer is -> %d\n", JS(num, k));
    return 0;
}