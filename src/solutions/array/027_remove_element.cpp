/*
 * LeetCode #27 - Remove Element
 * https://leetcode.com/problems/remove-element/
 * Difficulty: Easy
 */

#include <iostream>
#include <vector>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p027 {
void test() {
    Solution sol;
    
    vector<int> nums1 = {3, 2, 2, 3};
    cout << "Test 1: " << sol.removeElement(nums1, 3) << " (expected: 2)" << endl;
    
    vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    cout << "Test 2: " << sol.removeElement(nums2, 2) << " (expected: 5)" << endl;
}
REGISTER_PROBLEM(27, "Remove Element")
}
