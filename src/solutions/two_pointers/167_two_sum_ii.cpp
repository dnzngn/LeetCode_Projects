/*
 * LeetCode #167 - Two Sum II - Input Array Is Sorted
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
 * Difficulty: Medium
 */

#include <iostream>
#include <vector>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target) {
                return {left + 1, right + 1};
            } else if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }

        return {};
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p167 {
void test() {
    Solution sol;
    
    vector<int> nums1 = {2, 7, 11, 15};
    auto res1 = sol.twoSum(nums1, 9);
    cout << "Test 1: [" << res1[0] << ", " << res1[1] << "] (expected: [1, 2])" << endl;
    
    vector<int> nums2 = {2, 3, 4};
    auto res2 = sol.twoSum(nums2, 6);
    cout << "Test 2: [" << res2[0] << ", " << res2[1] << "] (expected: [1, 3])" << endl;
}
REGISTER_PROBLEM(167, "Two Sum II")
}
