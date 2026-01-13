/*
 * LeetCode #12 - Integer to Roman
 * https://leetcode.com/problems/integer-to-roman/
 * Difficulty: Medium
 */

#include <iostream>
#include <string>
#include <vector>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> valueSymbols = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        string result;
        
        for (const auto& [value, symbol] : valueSymbols) {
            while (num >= value) {
                result += symbol;
                num -= value;
            }
        }

        return result;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p012 {
void test() {
    Solution sol;
    
    cout << "Test 1: " << sol.intToRoman(3749) << " (expected: MMMDCCXLIX)" << endl;
    cout << "Test 2: " << sol.intToRoman(58) << " (expected: LVIII)" << endl;
    cout << "Test 3: " << sol.intToRoman(1994) << " (expected: MCMXCIV)" << endl;
}
REGISTER_PROBLEM(12, "Integer to Roman")
}
