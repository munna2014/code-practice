#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";
        for (const string& str : strs) {
            encoded += to_string(str.size()) + ":" + str;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        while (i < s.size()) {
            // Find the position of the delimiter ':'
            int colonPos = s.find(':', i);
            int len = stoi(s.substr(i, colonPos - i)); // Extract the length
            i = colonPos + 1;                         // Move past the delimiter
            decoded.push_back(s.substr(i, len));      // Extract the string of 'len' length
            i += len;                                // Move to the next part
        }
        return decoded;
    }
};

int main() {
    Codec codec;

    // User input for the list of strings
    vector<string> strs;
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;

    cout << "Enter the strings (one per line):" << endl;
    cin.ignore(); // To ignore the newline after entering 'n'

    for (int i = 0; i < n; ++i) {
        string temp;
        getline(cin, temp);
        strs.push_back(temp);
    }

    // Encode the strings
    string encoded = codec.encode(strs);
    cout << "\nEncoded string: " << encoded << endl;

    // Decode the strings
    vector<string> decoded = codec.decode(encoded);
    cout << "\nDecoded strings:" << endl;
    for (const string& str : decoded) {
        cout << str << endl;
    }

    return 0;
}
