/*
 * LeetCode #50 - Pow(x)
 * https://leetcode.com/problems/powx-n/
 * Difficulty: Medium
 */

#include <iostream>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;           // n = INT_MIN olursa taşma olmasın
        if (N < 0) {
            x = 1.0 / x;
            N = -N;
        }

        double result = 1.0;
        while (N > 0) {
            if (N & 1) result *= x; // bit 1 ise çarp
            x *= x;                 // karesini al
            N >>= 1;                // n'i ikiye böl
        }
        return result;
    }
};

// ==================== LEETCODE SOLUTION END ====================

namespace p050 {
void test() {
    Solution sol;
    double x1{2.0},x2{2.1},x3{2.0},x4{8.88023};
    int n1{10},n2{3},n3{-2},n4{3};


    cout << "Test 1: " << sol.myPow(x1,n1) << " (expected: 1024.00000)" << endl;
    cout << "Test 2: " << sol.myPow(x2,n2) << " (expected: 9.26100)" << endl;
    cout << "Test 3: " << sol.myPow(x3,n3) << " (expected: 0.25)" << endl;
    cout << "Test 4: " << sol.myPow(x4,n4) << " (expected: 700.28148)" << endl;
}
REGISTER_PROBLEM(50, "Pow(x,n)")
}
