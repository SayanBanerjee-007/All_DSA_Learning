#include <iostream>
#include <unordered_set>

using namespace std;

int union_of_array(int arr1[], int arr2[], int size1, int size2)
{
    unordered_set<int> set;
    for (int i = 0; i < size1; i++)
    {
        set.insert(arr1[i]);
    }
    for (int i = 0; i < size2; i++)
    {
        set.insert(arr2[i]);
    }
    return set.size();
}
int main()
{
    int arr1[] = {5, 4, 5, 7, 3, 2, 1, 7, 7, 2, 3};
    int size1 = sizeof(arr1) / sizeof(int);
    int arr2[] = {53, 4, 5, 6, 7, 8, 2, 0};
    int size2 = sizeof(arr2) / sizeof(int);

    int res = union_of_array(arr1, arr2, size1, size2);
    cout << "Union of two arrays is -> " << res;

    cout << endl;
    return 0;
}