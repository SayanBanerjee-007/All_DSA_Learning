#include <iostream>
#include <unordered_set>

using namespace std;

// It is a programe to find number of times a couple of elements present in two different arrays 
// and one element's couple will not be taken in count if there already a couple exsits of that particular element
int Intersection_of_array(int arr1[], int arr2[], int size1, int size2)
{
    unordered_set<int> set;
    int count = 0;
    for (int i = 0; i < size1; i++)
    {
        set.insert(arr1[i]);
    }
    for (int i = 0; i < size2; i++)
    {
        if (set.find(arr2[i]) != set.end())
        {
            count++;
            set.erase(arr2[i]);
        }
    }
    return count;
}
int main()
{
    int arr1[] = {5, 10, 15, 5, 10};
    int size1 = sizeof(arr1) / sizeof(int);
    int arr2[] = {15, 5, 5, 10, 4};
    int size2 = sizeof(arr2) / sizeof(int);

    int res = Intersection_of_array(arr1, arr2, size1, size2);
    cout << "Intersection of two arrays is -> " << res;

    cout << endl;
    return 0;
}