// Isyana is given the number of visitors at her local theme park on N consecutive days. The
// number of visitors on the i-th day is V(i). A day is record breaking if it satisfies both of the
// following condition:
// 1. The number of visitors on the day is strictly larger than the number of visitors on each of the previious days.
// 2. Either it is the last day, or the number of visitors on the day is strictly larger than the number of visitors on the following day.
#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 2, 0, 7, 5, 9, 2, 2};
    int size = sizeof(arr) / sizeof(int);
    int mx = arr[0], ans = 0;
    if (size == 1)
    {
        cout << "Number of record breaking days -> 1" << endl;
    }
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > mx && arr[i] > arr[i + 1])
        {
            ans++;
        }
        mx = max(mx, arr[i]);
    }
    cout << "Number of record breaking days -> " << ans << endl;
    return 0;
}