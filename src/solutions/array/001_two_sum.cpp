/*
 * LeetCode #1 - Two Sum
 * https://leetcode.com/problems/two-sum/
 * Difficulty: Easy
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (map.find(complement) != map.end()) {
                return {map[complement], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p001 {
void test() {
    Solution sol;
    
    vector<int> nums1 = {2, 7, 11, 15};
    auto res1 = sol.twoSum(nums1, 9);
    cout << "Test 1: [" << res1[0] << ", " << res1[1] << "] (expected: [0, 1])" << endl;
    
    vector<int> nums2 = {3, 2, 4};
    auto res2 = sol.twoSum(nums2, 6);
    cout << "Test 2: [" << res2[0] << ", " << res2[1] << "] (expected: [1, 2])" << endl;
}
REGISTER_PROBLEM(1, "Two Sum")
}
