/*
 * LeetCode #55 - Jump Game
 * https://leetcode.com/problems/jump-game/
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
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (i > farthest) {
                return false;
            }
            farthest = max(farthest, i + nums[i]);
            if (farthest >= n - 1) {
                return true;
            }
        }

        return false;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p055 {
void test() {
    Solution sol;
    
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Test 1: " << boolalpha << sol.canJump(nums1) << " (expected: true)" << endl;
    
    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << "Test 2: " << boolalpha << sol.canJump(nums2) << " (expected: false)" << endl;
}
REGISTER_PROBLEM(55, "Jump Game")
}
