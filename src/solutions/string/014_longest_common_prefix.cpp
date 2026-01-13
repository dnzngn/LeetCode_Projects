/*
 * LeetCode #14 - Longest Common Prefix
 * https://leetcode.com/problems/longest-common-prefix/
 * Difficulty: Easy
 */

#include <iostream>
#include <string>
#include <vector>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        string prefix = strs[0];
        
        for (int i = 1; i < strs.size(); ++i) {
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.size() - 1);
                if (prefix.empty()) return "";
            }
        }
        
        return prefix;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p014 {
void test() {
    Solution sol;
    
    vector<string> strs1 = {"flower", "flow", "flight"};
    cout << "Test 1: " << sol.longestCommonPrefix(strs1) << " (expected: fl)" << endl;
    
    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << "Test 2: " << sol.longestCommonPrefix(strs2) << " (expected: )" << endl;
}
REGISTER_PROBLEM(14, "Longest Common Prefix")
}
