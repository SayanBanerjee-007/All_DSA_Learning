// You are given an array arr[] of N integers including 0. The task is to find the smallest
// positive number missing from the array.

#include <iostream>

using namespace std;

int maximum(int arr[], int size)
{
    int mx = arr[0];
    for (int i = 1; i < size; i++)
    {
        mx = max(mx, arr[i]);
    }
    return mx;
}
int main()
{
    int arr[] = {0, -9, 1, 3, -4, 5};
    int size = sizeof(arr) / sizeof(int);
    const int len = maximum(arr, size);
    bool check[len];
    int ans = -1;
    for (int i = 0; i < len; i++)
    {
        check[i] = false;
    }
    for (int i = 0; i < size; i++)
    {
        if (arr[i] >= 0)
        {
            check[arr[i]] = true;
        }
    }
    for (int i = 0; i < len; i++)
    {
        if (check[i] == false)
        {
            ans = i;
            break;
        }
    }
    cout << ans << endl;

    return 0;
}