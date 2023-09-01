#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    unordered_set<int> s;

    // OPERATION -
    // insert() , find() , end() , begin() , clear() , size() , count() , erase()

    // Insertion
    s.insert(5);
    s.insert(45);
    // find and end
    if (s.find(45) == s.end())
    {
        cout << "Not found.\n";
    }
    else
    {
        cout << "Found.\n";
    }
    // begin
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << (*it) << endl;
    }
    // clear
    s.clear();
    // size
    cout << "size -> " << s.size();

    s.insert(5);
    s.insert(10);
    s.insert(7);

    // count
    cout << "10 is present" << s.count(10) << "times." << endl;
    if (s.count(5) == 0)
        cout << "Element is not present\n";
        
    // erase
    s.erase(5); // to erase all 5 int the hash
    s.erase(s.begin(), s.end());




    cout << endl;
    return 0;
}