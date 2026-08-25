/*
 * LeetCode #224 - Basic Calculator
 * https://leetcode.com/problems/basic-calculator/?envType=study-plan-v2&envId=top-interview-150
 * Difficulty: Hard
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

#include <stack>

#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    int calculate(string s) {
        stack<int> st;          // holds suspended (result, sign) pairs
        long long result = 0;
        int sign = +1;

        for (size_t i = 0; i < s.size(); i++) {
            char c = s[i];

            if (c == ' ') {
                continue;
            }
            else if (c == '+') {
                sign = +1;
            }
            else if (c == '-') {
                sign = -1;
            }
            else if (c == '(') {
                st.push(static_cast<int>(result));   // save outer running total
                st.push(sign);                       // save sign in front of '('
                result = 0;                          // start fresh inside
                sign   = +1;
            }
            else if (c == ')') {
                int savedSign   = st.top(); st.pop();   // LIFO: sign comes back first
                int savedResult = st.top(); st.pop();
                result = result * savedSign + savedResult;
            }
            else {  // digit
                long long num = 0;
                while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;                                 // for-loop will i++ again
                result += num * sign;
            }
        }

        return static_cast<int>(result);
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p224 {
void test() {

    Solution sol;
    
    string ask1 = {"1+1"};
    auto ans1 = sol.calculate(ask1);

    cout << "\nTest 1: " << ans1 << " (expected: 2)\n";

    cout << "\n============================================\n";

    string ask2 ={" 2-1 + 2 "};

    auto ans2 = sol.calculate(ask2);

    cout << "\nTest 2: " << ans2 << " (expected: 3)\n";

    cout << "\n============================================\n";

    string ask3 = {"(1+(4+5+2)-3)+(6+8)"};

    auto ans3 = sol.calculate(ask3);

    cout << "\nTest 3: " << ans3 << " (expected: 23)\n";

    cout << "\n============================================\n";
}

REGISTER_PROBLEM(224, "Basic Calculator")
}
