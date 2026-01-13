/*
 * LeetCode #169 - Majority Element
 * https://leetcode.com/problems/majority-element/
 * Difficulty: Easy
 * Algorithm: Boyer-Moore Voting Algorithm O(1) space
 */

#include <iostream>
#include <vector>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p169 {
void test() {
    Solution sol;
    
    vector<int> nums1 = {3, 2, 3};
    cout << "Test 1: " << sol.majorityElement(nums1) << " (expected: 3)" << endl;
    
    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    cout << "Test 2: " << sol.majorityElement(nums2) << " (expected: 2)" << endl;
}
REGISTER_PROBLEM(169, "Majority Element")
}
