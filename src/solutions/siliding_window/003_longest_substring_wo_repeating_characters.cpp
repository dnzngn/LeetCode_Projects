/*
 * LeetCode #3 - Longest Substring Without Repeating Characters
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/?envType=study-plan-v2&envId=top-interview-150
 * Difficulty: Medium
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    int lengthOfLongestSubstring(string s){
        int n = s.size();
        int left = 0;
        int best = 0;
        string sub_string;
        unordered_set<char> seen;

        for(int right = 0; right < n; right++){

            

            while(seen.find(s[right]) != seen.end()){

                seen.erase(s[left]);
                left++;

                

            }

            seen.insert(s[right]);

            best = max(best, right - left + 1);
        }
                 
        return best;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p003 {
void test() {
    Solution sol;

    string s0{"abcabccbb"};

    cout << "\nTest 1:\n" << sol.lengthOfLongestSubstring(s0) << " (expected: 3)\n";

    cout << "\n============================================\n";

    string s1{"bbbbb"};

    cout << "\nTest 2: " << sol.lengthOfLongestSubstring(s1) << " (expected: 1)\n";

    cout << "\n============================================\n";

    string s2{"pwwkew"};

    cout << "\nTest 3: " << sol.lengthOfLongestSubstring(s2) << " (expected: 3)\n";

    cout << "\n============================================\n";


}
REGISTER_PROBLEM(3, "Longest Substring Without Repeating Characters")
}
