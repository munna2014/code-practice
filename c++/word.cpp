#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    string str = "My name is Munna karim";
    string word;
    stringstream ss(str);
    int count = 0;

    while (ss >> word)
        count++;
    cout << "Word count: " << count << endl;
    return 0;
}
