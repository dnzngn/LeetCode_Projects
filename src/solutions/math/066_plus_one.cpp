/*
 * LeetCode #66 - Plus One
 * https://leetcode.com/problems/plus-one/
 * Difficulty: Easy
 */

#include <iostream>
#include <vector>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p066 {
void test() {
    Solution sol;
    
    vector<int> digits1 = {1, 2, 3};
    auto res1 = sol.plusOne(digits1);
    cout << "Test 1: [";
    for (int i = 0; i < res1.size(); i++) {
        cout << res1[i];
        if (i < res1.size() - 1) cout << ", ";
    }
    cout << "] (expected: [1, 2, 4])" << endl;
    
    vector<int> digits2 = {9, 9, 9};
    auto res2 = sol.plusOne(digits2);
    cout << "Test 2: [";
    for (int i = 0; i < res2.size(); i++) {
        cout << res2[i];
        if (i < res2.size() - 1) cout << ", ";
    }
    cout << "] (expected: [1, 0, 0, 0])" << endl;
}
REGISTER_PROBLEM(66, "Plus One")
}
