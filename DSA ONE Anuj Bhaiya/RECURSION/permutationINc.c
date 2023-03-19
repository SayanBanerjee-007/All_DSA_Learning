#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
    *a = *a + *b - (*b = *a);
}
void permutation(char *str, int l, int r)
{
    static int count = 1;
    if (l == r)
    {
        printf("%d . %s\n", count, str);
        count++;
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(str+l, str+i);
            permutation(str, l + 1, r);
            swap(str+l, str+i);
        }
    }
}

int main()
{
    char str[100];
    printf("Enter your string: ");
    gets(str);
    permutation(str, 0, strlen(str) - 1);

    return 0;
}