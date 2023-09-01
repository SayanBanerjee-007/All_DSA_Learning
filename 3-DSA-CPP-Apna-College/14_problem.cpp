// write a program to print how many numbers are divisible by A and B from range 1 to N
#include <iostream>

using namespace std;
int divisible_count(int n, int a, int b)
{
    // int sum =0;
    // sum += n/a;
    // sum += n/b;
    // sum -= n/(a*b);
    // return sum;
    return (n / a + n / b) - n / (a * b);
}
int main()
{
    int a, b, n;
    cout << "Enter limit: ";
    cin >> n;
    cout << "Enter A and B: ";
    cin >> a >> b;
    cout << divisible_count(n, a, b);

    cout << endl;
    return 0;
}