/*
 * LeetCode #69 - Sqrt(x)
 * https://leetcode.com/problems/sqrtx/
 * Difficulty: Easy
 */

#include <iostream>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        
        long long left = 1, right = x;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (mid * mid == x) {
                return mid;
            } else if (mid * mid < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return right;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p069 {
void test() {
    Solution sol;
    
    cout << "Test 1: " << sol.mySqrt(4) << " (expected: 2)" << endl;
    cout << "Test 2: " << sol.mySqrt(8) << " (expected: 2)" << endl;
    cout << "Test 3: " << sol.mySqrt(16) << " (expected: 4)" << endl;
}
REGISTER_PROBLEM(69, "Sqrt(x)")
}
