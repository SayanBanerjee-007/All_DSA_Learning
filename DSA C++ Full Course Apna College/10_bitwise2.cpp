// write a program to count number of ones present in the binary format of a number
#include <iostream>

using namespace std;

int main()
{
    int count = 0, num;
    cout << "Enter your number: ";
    cin >> num;
    while (num)
    {
        if(1 & num)
        count++;
        num >>= 1;
    }
    cout<<"Ones in the binary format of the given number is "<<count;
    cout << endl;
    return 0;
}