/*
 * LeetCode #26 - Remove Duplicates from Sorted Array
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 * Difficulty: Easy
 */

#include <iostream>
#include <vector>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int index = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p026 {
void test() {
    Solution sol;
    
    vector<int> nums1 = {1, 1, 2};
    cout << "Test 1: " << sol.removeDuplicates(nums1) << " (expected: 2)" << endl;
    
    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << "Test 2: " << sol.removeDuplicates(nums2) << " (expected: 5)" << endl;
}
REGISTER_PROBLEM(26, "Remove Duplicates from Sorted Array")
}
