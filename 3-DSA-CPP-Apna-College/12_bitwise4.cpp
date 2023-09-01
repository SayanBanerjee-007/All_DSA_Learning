// write a program to print subset of a string
#include <iostream>

using namespace std;
void subset(char *str, int lim)
{
    for (int i = 0; i < (1 << lim); i++)
    {
        for (int j = 0; j < lim; j++)
        {
            if (i & (1 << j))
                cout << str[j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int lim, i = 0;
    cout << "Enter how many character you want to input? -> ";
    cin >> lim;
    char *str = new char[lim];
    cout << "Enter your characters: \n";
    while (i < lim)
    {
        cin >> str[i];
        i++;
    }
    cout << "Subsets:\n";
    subset(str, lim);

    cout << endl;
    return 0;
}