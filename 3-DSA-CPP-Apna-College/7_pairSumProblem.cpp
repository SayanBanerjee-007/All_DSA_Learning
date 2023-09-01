//Check if there exists two elementts in an array that their sum is equal to given k
#include <iostream>

using namespace std;
void pairsum(int arr[], int size, int key)
{
    int low = 0;
    int high = size - 1;
    while (low < high)
    {

        if (arr[low] + arr[high] == key)
        {
            cout << "array[" << low << "]"
                 << " + "
                 << "array[" << high << "]"
                 << " = " << key;
            return;
        }
        else if (arr[low] + arr[high] < key)
            low++;
        else
            high--;
    }
    cout << "There is no such pair of elements that sum is equal to " << key;
}

int main()
{
    int arr[] = {2, 4, 7, 11, 14, 16, 20, 21}; // array should be sorted
    int size = sizeof(arr) / sizeof(int);
    int key;
    cout << "Enter the sum you are searching: ";
    cin >> key;
    pairsum(arr, size, key);

    cout << endl;
    return 0;
}