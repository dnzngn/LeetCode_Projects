/*
 * LeetCode #172 - Factorial Trailing Zeroes
 * https://leetcode.com/problems/factorial-trailing-zeroes/
 * Difficulty: Medium
 */

#include <iostream>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while (n >= 5) {
            count += n / 5;
            n /= 5;
        }
        return count;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p172 {
void test() {
    Solution sol;
    
    cout << "Test 1: " << sol.trailingZeroes(3) << " (expected: 0)" << endl;
    cout << "Test 2: " << sol.trailingZeroes(5) << " (expected: 1)" << endl;
    cout << "Test 3: " << sol.trailingZeroes(25) << " (expected: 6)" << endl;
}
REGISTER_PROBLEM(172, "Factorial Trailing Zeroes")
}
