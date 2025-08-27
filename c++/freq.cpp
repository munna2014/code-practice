#include <iostream>
#include <map>
using namespace std;

int main()
{
    string str = "banana";
    map<char, int> freq;

    for (char c : str)
        freq[c]++;

    for (auto p : freq)
        cout << p.first << " -> " << p.second << endl;
    return 0;
}
