/*
 * LeetCode #071 - Simplfy Path
 * https://leetcode.com/problems/simplify-path/description/?envType=study-plan-v2&envId=top-interview-150
 * Difficulty: Medium
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

#include <stack>

#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    string simplifyPath(string path) {
        vector<string_view> stack;
        string_view sv{path};

        string out;

        size_t total = 0;
        size_t i = 0;

        while (i < sv.size()) {

            while (i < sv.size() && sv[i] == '/') 
                ++i;      // skip separators

            if (i == sv.size()) 
                break;

            size_t j = i;

            while (j < sv.size() && sv[j] != '/') 
                ++j;      // scan one token

            string_view token = sv.substr(i, j - i);        // no allocation
            i = j;

            if (token == ".") 
                continue;
            
            if (token == "..") {
                if (!stack.empty()) 
                    stack.pop_back();
            } else {
                stack.push_back(token);
            }
        }

        if (stack.empty()) 
            return "/";

        
        for (auto t : stack) 
            total += t.size() + 1;

        
        out.reserve(total);                                  // single allocation

        for (auto t : stack) { 
            out += '/'; 
            out += t;
        }
        return out;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p71 {
void test() {
    Solution sol;
    
    string s1 = "/home/";

    auto ans1 = sol.simplifyPath(s1);

    cout << "\nTest 1: " << ans1 << " (expected: /home)\n";

    cout << "\n============================================\n";
    string s2 = "/home//foo/";

    auto ans2 = sol.simplifyPath(s2);
        
    cout << "\nTest 2: " << ans2 << " (expected: /home/foo)\n";

    cout << "\n============================================\n";
    string s3 = "/home/user/Documents/../Pictures";

    auto ans3 = sol.simplifyPath(s3);

    cout << "\nTest 3: " << ans3 << " (expected: /home/user/Pictures)\n";

    cout << "\n============================================\n";
    string s4 = "/../";

    auto ans4 = sol.simplifyPath(s4);

    cout << "\nTest 4: " << ans4 << " (expected: /)\n";

    cout << "\n============================================\n";

    string s5 = "/.../a/../b/c/../d/./";

    auto ans5 = sol.simplifyPath(s5);

    cout << "\nTest 5: " << ans5 << " (expected: /.../b/d)\n";

    cout << "\n============================================\n";
}

REGISTER_PROBLEM(71, "Simplfy Path")
}
