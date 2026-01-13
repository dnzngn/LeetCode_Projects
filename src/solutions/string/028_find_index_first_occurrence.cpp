/*
 * LeetCode #28 - Find the Index of the First Occurrence in a String
 * https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
 * Difficulty: Easy
 */

#include <iostream>
#include <string>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size()) {
            return -1;
        }

        for (int i = 0; i <= (int)(haystack.size() - needle.size()); ++i) {
            if (haystack[i] == needle[0]) {
                if (needle == haystack.substr(i, needle.size())) {
                    return i;
                }
            }
        }

        return -1;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p028 {
void test() {
    Solution sol;
    
    cout << "Test 1: " << sol.strStr("sadbutsad", "sad") << " (expected: 0)" << endl;
    cout << "Test 2: " << sol.strStr("leetcode", "leeto") << " (expected: -1)" << endl;
}
REGISTER_PROBLEM(28, "Find the Index of the First Occurrence")
}
