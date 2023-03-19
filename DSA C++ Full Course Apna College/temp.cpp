#include <iostream>
using namespace std;

struct atm
{
    int n;
    int k;
    int arr[100];
};
struct idk
{
    string str;
};

int main()
{
    int t, sum = 0;
    cin >> t;
    struct atm *obj = new struct atm[t];
    struct idk *wtf = new struct idk[t];

    for (int i = 0; i < t; i++)
    {
        cin >> obj[i].n >> obj[i].k;
        for (int j = 0; j < obj[i].n; j++)
        {
            cin >> obj[i].arr[j];
            if ((sum + obj[i].arr[j]) <= obj[i].k)
            {
                sum += obj[i].arr[j];
                wtf[i].str[j] = '1';
            }
            else
            {
                wtf[i].str[j] = '0';
            }
        }
        sum = 0;
    }

    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < obj[i].n; j++)
            cout << wtf[i].str[j];
        cout << endl;
    }
    return 0;
}
