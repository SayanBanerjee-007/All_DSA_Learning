// write a program to find two unique nubers in an array where all other numbers are in the power of two
#include <iostream>

using namespace std;

void unique_two(int arr[], int size)
{
    int x = 0, a = 0, b = 0;
    for (int i = 0; i < size; i++)
    {
        x ^= arr[i];
    }
    int last_set_bit = x & (-x);
    for (int i = 0; i < size; i++)
    {
        if (arr[i] & last_set_bit)
            a ^= arr[i];
        else
            b ^= arr[i];
    }
    cout << "unique two numbers are : " << a << " and " << b;
}
int main()
{
    int arr[] = {1, 1, 2, 4, 5, 3, 3, 4};
    int size = sizeof(arr) / sizeof(int);
    unique_two(arr, size);
    cout << endl;
    return 0;
}