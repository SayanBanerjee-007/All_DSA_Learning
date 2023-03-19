#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void permutation(string str, int l, int r)
{
    static int count = 1;
    if (l == r)
    {
        cout << count << ". " << str << "\n";
        count++;
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(str[l], str[i]);
            permutation(str, l + 1, r);
            swap(str[l], str[i]);
        }
    }
}
int main()
{
    string str;
    cout << "Enter your string: ";
    cin >> str;
    permutation(str, 0, str.length() - 1);
    cout << endl;
    return 0;
}
