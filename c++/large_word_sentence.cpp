#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    string sentence = "C++ programming language";
    string word, longest;
    stringstream ss(sentence);

    while (ss >> word)
    {
        if (word.length() > longest.length())
            longest = word;
    }
    cout << "Longest word: " << longest << endl;
    return 0;
}
