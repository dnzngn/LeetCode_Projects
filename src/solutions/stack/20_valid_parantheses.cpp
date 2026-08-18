/*
 * LeetCode #020 - Valid Parentheses
 * https://leetcode.com/problems/valid-parentheses/description/?envType=study-plan-v2&envId=top-interview-150
 * Difficulty: Easy
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    bool isValid(string s) {

        
        
        return false;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p20 {
void test() {
    Solution sol;
    
    string s1 = "()";

    auto ans1 = sol.isValid(s1);

    cout << "\nTest 1: " << ans1 << " (expected: true)\n";

    cout << "\n============================================\n";
    string s2 = "()[]{}";

    auto ans2 = sol.isValid(s2);
        
    cout << "\nTest 2: " << ans2 << " (expected: true)\n";

    cout << "\n============================================\n";
    string s3 = "(]";

    auto ans3 = sol.isValid(s3);

    cout << "\nTest 3: " << ans3 << " (expected: false)\n";

    cout << "\n============================================\n";
    string s4 = "([])";

    auto ans4 = sol.isValid(s4);

    cout << "\nTest 4: " << ans4 << " (expected: true)\n";

    cout << "\n============================================\n";

    string s5 = "([)]";

    auto ans5 = sol.isValid(s5);

    cout << "\nTest 5: " << ans5 << " (expected: false)\n";

    cout << "\n============================================\n";
}

REGISTER_PROBLEM(20, "Valid Parentheses")
}
