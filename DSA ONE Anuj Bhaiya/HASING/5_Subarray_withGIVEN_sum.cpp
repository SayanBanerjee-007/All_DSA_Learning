#include <iostream>
#include <unordered_map>

using namespace std;

void subArraySum(int arr[], int n, int sum)
{
    unordered_map<int, int> map;
    int curr_sum = 0;

    for (int i = 0; i < n; i++)
    {
        curr_sum += arr[i];

        if (curr_sum == sum)
        {
            cout << "Sum found between indexes " << 0 << " to " << i << endl;
            return;
        }

        if (map.find(curr_sum - sum) != map.end())
        {
            cout << "Sum found between indexes " << map[curr_sum - sum] + 1 << " to " << i << endl;
            return;
        }
        map[curr_sum] = i;
    }
    cout << "No subarray with given sum exists";
}
int main()
{
    int arr[] = {10, 15, -5, 15, -10, 5};
    int size = sizeof(arr) / sizeof(int);
    int sum = 5;
    subArraySum(arr, size, sum);

    cout << endl;
    return 0;
}