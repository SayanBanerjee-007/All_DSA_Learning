// Given an array arr[] of size N. The task is to find the first repeating element in the array of
// integers, i.e. , an element that occurs more than once and whose index of first occurrence is
// smallest.
#include <iostream>

using namespace std;

int big(int arr[], int size)
{
    int mx = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (mx < arr[i])
            mx = arr[i];
    }
    return mx;
}
int main()
{
    int arr[] = {1, 5, 3, 4, 3, 5, 6};
    int size = sizeof(arr) / sizeof(int);
    int len = big(arr, size)+1;
    int cpy[len];
    for (int i = 0; i < len; i++)
    {
        cpy[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        cpy[arr[i]]++;
    }
    cout << big(cpy, len) << endl;

    cout << endl;
    return 0;
}