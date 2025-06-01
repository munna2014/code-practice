#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
public:
    int romanToInt(const std::string& s) {
        // Map of Roman numerals and their integer values
        std::unordered_map<char, int> romanValues = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int result = 0; // Store the integer result
        int n = s.length();

        for (int i = 0; i < n; i++) {
            // If the current value is less than the next value, subtract it
            if (i < n - 1 && romanValues[s[i]] < romanValues[s[i + 1]]) {
                result -= romanValues[s[i]];
            } else {
                // Otherwise, add it
                result += romanValues[s[i]];
            }
        }

        return result;
    }
};

int main() {
    Solution solution;

    // Test cases
    std::cout << solution.romanToInt("III") << std::endl;     // Output: 3
    std::cout << solution.romanToInt("IV") << std::endl;      // Output: 4
    std::cout << solution.romanToInt("IX") << std::endl;      // Output: 9
    std::cout << solution.romanToInt("LVIII") << std::endl;   // Output: 58
    std::cout << solution.romanToInt("MCMXCIV") << std::endl; // Output: 1994

    return 0;
}
