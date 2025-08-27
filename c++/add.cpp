#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string N;
    cout << "Enter a large number: ";
    cin >> N;

    // Add one to the number
    reverse(N.begin(), N.end()); // Reverse the string for easier manipulation
    int carry = 1;              // We are adding 1, so the initial carry is 1
    for (size_t i = 0; i < N.size(); ++i) {
        int digit = N[i] - '0'; // Convert character to integer
        digit += carry;         // Add carry to the digit
        if (digit > 9) {
            N[i] = '0';         // Reset current digit to 0
            carry = 1;          // Carry over to the next digit
        } else {
            N[i] = digit + '0'; // Update the current digit
            carry = 0;          // No carry-over needed
            break;              // Addition complete
        }
    }

    if (carry == 1) {
        N.push_back('1'); // If there's still a carry, add a new digit
    }

    reverse(N.begin(), N.end()); // Reverse back to the original order
    cout << "Result: " << N << endl;

    return 0;
}
