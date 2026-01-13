/*
 * LeetCode #15 - 3Sum
 * https://leetcode.com/problems/3sum/
 * Difficulty: Medium
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < (int)nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    while (left < right && nums[right] == nums[right - 1]) --right;

                    ++left;
                    --right;
                } else if (sum < 0) {
                    ++left;
                } else {
                    --right;
                }
            }
        }

        return result;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p015 {
void test() {
    Solution sol;
    
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    auto res1 = sol.threeSum(nums1);
    cout << "Test 1: " << res1.size() << " triplets (expected: 2)" << endl;
}
REGISTER_PROBLEM(15, "3Sum")
}
