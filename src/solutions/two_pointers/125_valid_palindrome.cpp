/*
 * LeetCode #125 - Valid Palindrome
 * https://leetcode.com/problems/valid-palindrome/
 * Difficulty: Easy
 */

#include <iostream>
#include <string>
#include <cctype>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        
        while (left < right) {
            while (left < right && !isalnum(s[left])) left++;
            while (left < right && !isalnum(s[right])) right--;
            
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p125 {
void test() {
    Solution sol;
    
    cout << "Test 1: " << boolalpha << sol.isPalindrome("A man, a plan, a canal: Panama") << " (expected: true)" << endl;
    cout << "Test 2: " << boolalpha << sol.isPalindrome("race a car") << " (expected: false)" << endl;
}
REGISTER_PROBLEM(125, "Valid Palindrome")
}
