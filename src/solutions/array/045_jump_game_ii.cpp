/*
 * LeetCode #45 - Jump Game II
 * https://leetcode.com/problems/jump-game-ii/
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
    int jump(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = max(nums[i] + i, nums[i - 1]);
        }

        int ind = 0;
        int ans = 0;

        while (ind < (int)nums.size() - 1) {
            ans++;
            ind = nums[ind];
        }

        return ans;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p045 {
void test() {
    Solution sol;
    
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Test 1: " << sol.jump(nums1) << " (expected: 2)" << endl;
    
    vector<int> nums2 = {2, 3, 0, 1, 4};
    cout << "Test 2: " << sol.jump(nums2) << " (expected: 2)" << endl;
}
REGISTER_PROBLEM(45, "Jump Game II")
}
