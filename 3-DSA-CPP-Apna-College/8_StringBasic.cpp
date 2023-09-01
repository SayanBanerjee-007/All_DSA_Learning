#include <iostream>
#include <string>    // For string function
#include <algorithm> // For sorting in string and blah blah blah

using namespace std;

int main()
{
    string str = "Sayan";
    string str2(3, 'a'); // 3 times 'a' int str2 string
    string str3 = "LOLomggod";
    cout << str << endl
         << str2 << endl
         << str + str2 << endl;
    str.append(str2);
    cout << str << endl;
    str.clear();                 // clear all character from the string
    getline(cin, str);           // to input all the sentence
    int res = str2.compare(str); // if returns 0 both are same
    cout << res << endl;
    int res2 = str.empty(); // if the string is empty return true
    cout << res2 << endl;
    str3.erase(3, 3); // (the index to start erasing,how many indecies from the index)
    cout << str3 << endl;
    int res3 = str3.find("god"); // will return the position of 'g', the starting character of the given string
    cout << res3 << endl;
    str3.insert(3, "omg"); // add the given string at the given position
    cout << str3 << endl;
    int size_of_string = str.size(); // size of the array
    cout << size_of_string << endl;
    size_of_string = str.length(); // size of the array
    cout << size_of_string << endl;
    string sub = str3.substr(3, 3); //create sub string and return(starting index,how many indices from the index)
    cout << sub << endl;
    string number = "754";
    int num = stoi(number); // string to integer
    cout << num << endl;
    int x = 755;
    string y = to_string(x); // integer to string
    cout << y << endl;
    string last = "fjweahahfkajz";
    sort(last.begin(), last.end()); // sort the character in assending order or lexicographically sorted
    cout << last << endl;

    return 0;
}