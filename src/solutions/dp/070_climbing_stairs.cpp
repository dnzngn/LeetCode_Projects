/*
 * LeetCode #70 - Climbing Stairs
 * https://leetcode.com/problems/climbing-stairs/
 * Difficulty: Easy
 * Category: dp
 */


#include "registry.hpp"

namespace solutions::dp {

class Solution_070 {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int prev2 = 1, prev1 = 2;
        for (int i = 3; i <= n; ++i) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

void test() {
    Solution_070 sol;
    
    std::cout << "n=2: " << sol.climbStairs(2) << " (expected: 2)" << std::endl;
    std::cout << "n=3: " << sol.climbStairs(3) << " (expected: 3)" << std::endl;
    std::cout << "n=5: " << sol.climbStairs(5) << " (expected: 8)" << std::endl;
}

REGISTER_PROBLEM(70, "Climbing Stairs")

} // namespace solutions::dp
