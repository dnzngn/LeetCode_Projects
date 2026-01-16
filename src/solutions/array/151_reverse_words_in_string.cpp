/*
 * LeetCode #151 - Reverse Words in a String
 * https://leetcode.com/problems/reverse-words-in-a-string/
 * Difficulty: Medium
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    string reverseWords(string s) {
        string out;
        int i = (int)s.size() - 1;

        while (i >= 0) {

            while (i >= 0 && s[i] == ' ') 
                i--;
            if (i < 0) break;

            int end = i;

            while (i >= 0 && s[i] != ' ') 
                i--;
            int start = i + 1;

            if (!out.empty()) 
                out.push_back(' ');

            out.append(s, start, end - start + 1);
        }

        return out;
    }
};

// ==================== LEETCODE SOLUTION END ====================

namespace p151 {
void test() {
    Solution sol;
    
    string s("the sky is blue");
    auto res1 = sol.reverseWords(s);
    cout << "Test 1: [" << res1 << "] (expected: blue is sky the)" << endl;
    
    string s1("  hello world  ");
    auto res2 = sol.reverseWords(s1);
    cout << "Test 2: [" << res2 << "] (expected: [world hello])" << endl;

    string s2("a good   example");
    auto res3 = sol.reverseWords(s2);
    cout << "Test 3: [" << res3 << "] (expected: [example good a])" << endl;
}
REGISTER_PROBLEM(151, "Reverse Words in a String")
}
