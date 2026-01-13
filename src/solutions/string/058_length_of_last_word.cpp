/*
 * LeetCode #58 - Length of Last Word
 * https://leetcode.com/problems/length-of-last-word/
 * Difficulty: Easy
 */

#include <iostream>
#include <string>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int i = s.size() - 1;
        
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }
        
        return length;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p058 {
void test() {
    Solution sol;
    
    cout << "Test 1: " << sol.lengthOfLastWord("Hello World") << " (expected: 5)" << endl;
    cout << "Test 2: " << sol.lengthOfLastWord("   fly me   to   the moon  ") << " (expected: 4)" << endl;
    cout << "Test 3: " << sol.lengthOfLastWord("luffy is still joyboy") << " (expected: 6)" << endl;
}
REGISTER_PROBLEM(58, "Length of Last Word")
}
