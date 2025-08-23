#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main()
{
    string str = "programming";
    string result = "";
    unordered_set<char> seen;

    for (char c : str)
    {
        if (seen.find(c) == seen.end())
        {
            result += c;
            seen.insert(c);
        }
    }
    cout << "Without duplicates: " << result << endl;
    return 0;
}
