// Given string is palindrom or not ???
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrom(char *string, int left, int right)
{
    if (left >= right)
        return true;
    if (string[left] != string[right])
        return false;
    return isPalindrom(string, left + 1, right - 1);
}
int main()
{
    char string[100];
    printf("Enter your string: \n");
    gets(string);
    if (isPalindrom(string, 0, (strlen(string) - 1)))
    {
        printf("The string is palindrom.\n");
    }
    else
    {
        printf("The string is not palindrom.\n");
    }

    return 0;
}