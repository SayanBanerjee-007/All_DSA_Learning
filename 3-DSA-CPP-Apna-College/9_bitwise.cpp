// write a program to check if the given number is power of 2
#include<iostream>

using namespace std;

int main()
{
    int num;
    cout<<"Enter your number: ";
    cin>>num;
    if(!(num & (num-1)))
    cout<<"The given number "<<num<<" is power of 2";
    else
    cout<<"The given number "<<num<<" is not power of 2";
    cout<<endl;
    return 0;
}