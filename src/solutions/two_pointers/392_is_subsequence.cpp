/*
 * LeetCode #392 - Is Subsequence
 * https://leetcode.com/problems/is-subsequence/
 * Difficulty: Easy
 */

#include <iostream>
#include <string>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sIdx = 0;
        
        for (char c : t) {
            if (sIdx < (int)s.size() && s[sIdx] == c) {
                sIdx++;
            }
        }
        
        return sIdx == (int)s.size();
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p392 {
void test() {
    Solution sol;
    
    cout << "Test 1: " << boolalpha << sol.isSubsequence("abc", "ahbgdc") << " (expected: true)" << endl;
    cout << "Test 2: " << boolalpha << sol.isSubsequence("axc", "ahbgdc") << " (expected: false)" << endl;
}
REGISTER_PROBLEM(392, "Is Subsequence")
}
