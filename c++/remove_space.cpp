#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    stringstream ss(input);
    string word, result = "";

    while (ss >> word)
    {
        if (!result.empty())
            result += " ";
        result += word;
    }

    cout << "Processed string: \"" << result << "\"" << endl;
    return 0;
}
