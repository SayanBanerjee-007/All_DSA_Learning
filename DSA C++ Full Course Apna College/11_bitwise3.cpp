// write a program to generate all possible subset of a set(integer)
#include <iostream>

using namespace std;
void subset(int *arr,int n)
{
    for(int i=0;i<(1<<n);i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i & (1<<j))
            cout<<arr[j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cout << "How many numbers to insert? -> ";
    cin >> n;
    int *arr = new int[n];
    cout<<"Enter the numbers: \n";
    for(int i =0;i<n;i++)
        cin>>arr[i];
    subset(arr,n);

    cout<< endl;
    return 0;
}