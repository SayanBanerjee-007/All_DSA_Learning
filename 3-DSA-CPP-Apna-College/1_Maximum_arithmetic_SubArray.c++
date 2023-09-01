// Arithmetic Array
// An arithmetic array is an array that contains at least two integers and the differneces
// between consecutive integers are equal. For example, [9,10], [3,3,3], [9,7,5,3] are
// arithmetic arrays, while [1,3,3,7] and [1,2,4] are not arithmetic arrays.

// Maximum Arithmetic Subarrays -
#include <iostream>
using namespace std;
int Max_arithmetic_subarray(int arr[], int size)
{
    if (size <= 1)
    {
        return 0;
    }

    int pd = arr[1] - arr[0]; //--> previous common difference
    int curr = 2;             //--> Current Arithmetic Subarray Length
    int ans = 2;              //--> Max arithmetic subarray length

    for (int i = 2; i < size; i++)
    {
        if (pd != arr[i] - arr[i - 1])
        {
            curr = 1;
            pd = arr[i] - arr[i - 1];
        }
        if (pd == arr[i] - arr[i - 1])
        {
            curr++;
        }
        ans = max(curr, ans);
    }
    return ans;
}
int main()
{
    int arr[] = {10, 7, 4, 6, 8, 10, 11};
    int size = sizeof(arr) / sizeof(int);
    int len = Max_arithmetic_subarray(arr, size);
    if (len == 0)
    {
        cout << "Arithmetic Subarray Length atleast should be --> 2" << endl;
    }
    cout << "Maximum Arithmetic Subarray Length --> " << len << endl;
    return 0;
}