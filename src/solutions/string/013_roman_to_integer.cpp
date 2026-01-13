/*
 * LeetCode #13 - Roman to Integer
 * https://leetcode.com/problems/roman-to-integer/
 * Difficulty: Easy
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanMap = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int total = 0;
        int prevValue = 0;

        for (int i = s.size() - 1; i >= 0; --i) {
            int value = romanMap[s[i]];
            if (value < prevValue) {
                total -= value;
            } else {
                total += value;
            }
            prevValue = value;
        }

        return total;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p013 {
void test() {
    Solution sol;
    
    cout << "Test 1: " << sol.romanToInt("III") << " (expected: 3)" << endl;
    cout << "Test 2: " << sol.romanToInt("LVIII") << " (expected: 58)" << endl;
    cout << "Test 3: " << sol.romanToInt("MCMXCIV") << " (expected: 1994)" << endl;
}
REGISTER_PROBLEM(13, "Roman to Integer")
}
