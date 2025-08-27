#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "Hello World";

    for (char &c : str)
        c = toupper(c);
    cout << "Uppercase: " << str << endl;

    for (char &c : str)
        c = tolower(c);
    cout << "Lowercase: " << str << endl;
    return 0;
}
