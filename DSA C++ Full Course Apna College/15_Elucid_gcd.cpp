#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    // Using recursion
    /* if(a%b==0)
        return b;
    return gcd(b,a%b);
    */
    // Without using recursion
    while (b != 0)
    {
        int temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}
int main()
{
    int num1, num2;
    cout << "Enter first number -> ";
    cin >> num1;
    cout << "Enter second number -> ";
    cin >> num2;
    cout << "GCD of " << num1 << " and " << num2 << " is -> " << gcd(num1, num2);
    cout << endl;
    return 0;
}