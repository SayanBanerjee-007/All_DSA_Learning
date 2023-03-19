#include <iostream>
#include <unordered_set>

using namespace std;

int count_distinct(int arr[], int size)
{
    unordered_set<int> set;
    for (int i = 0; i < size; i++)
    {
        set.insert(arr[i]);
    }
    return set.size();
}
int main()
{
    int arr[] = {5, 4, 5, 7, 3, 2, 1, 7, 7, 2, 3};
    int size = sizeof(arr) / sizeof(int);

    int res = count_distinct(arr, size);
    cout << "Disrinct element is -> " << res;

    cout << endl;
    return 0;
}