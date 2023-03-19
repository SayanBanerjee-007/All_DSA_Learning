#include <iostream>

using namespace std;

int kaden(int arr[], int size)
{
    int cur_sum = 0, ans = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        cur_sum += arr[i];
        if (ans < cur_sum)
            ans = cur_sum;
        if (cur_sum < 0)
            cur_sum = 0;
    }
    return ans;
}
int main()
{
    int arr[] = {4, -4, 6, -6, 10, -11, 12};
    int size = sizeof(arr) / sizeof(int);

    int Non_warp_sum = kaden(arr, size);
    int Warp_sum;
    int total_non_warp_sum = 0;
    
    for (int i = 0; i < size; i++)
    {
        total_non_warp_sum += arr[i];
        arr[i] = -arr[i];
    }
    Warp_sum = total_non_warp_sum + kaden(arr,size);

    cout<< max(Non_warp_sum,Warp_sum);
    

    cout << endl;
    return 0;
}