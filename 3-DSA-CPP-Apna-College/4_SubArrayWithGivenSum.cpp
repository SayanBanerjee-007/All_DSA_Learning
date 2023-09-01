// Sub Array with given sum
#include <iostream>

using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 7, 5};
    int size = sizeof(arr) / sizeof(int);

    int given_sum, cur_sum = 0;
    cout << "Enter sum: ";
    cin >> given_sum;

    int start = -1, end = -1;
    int i = 0, j = 0;
    while (j < size && cur_sum + arr[j] <= given_sum)
    {
        cur_sum += arr[j];
        j++;
    }
    if (given_sum == cur_sum)
    {
        cout << "1 to " << j << endl;
        return 0;
    }
    while (j < size)
    {
        cur_sum += arr[j];
        while (cur_sum > given_sum)
        {
            cur_sum -= arr[i];
            i++;
        }
        if (cur_sum == given_sum)
        {
            start = i + 1;
            end = j + 1;
            break;
        }
        j++;
    }
    cout << start << " " << end <<endl;

    return 0;
}