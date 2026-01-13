/*
 * LeetCode #9 - Palindrome Number
 * https://leetcode.com/problems/palindrome-number/
 * Difficulty: Easy
 */

#include <iostream>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0))
            return false;

        long long reversed = 0;
        int original = x;

        while (x != 0) {
            int remainder = x % 10;
            x /= 10;
            reversed = reversed * 10 + remainder;
        }

        return reversed == original;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p009 {
void test() {
    Solution sol;
    
    cout << "Test 1: " << boolalpha << sol.isPalindrome(121) << " (expected: true)" << endl;
    cout << "Test 2: " << boolalpha << sol.isPalindrome(-121) << " (expected: false)" << endl;
    cout << "Test 3: " << boolalpha << sol.isPalindrome(10) << " (expected: false)" << endl;
}
REGISTER_PROBLEM(9, "Palindrome Number")
}
