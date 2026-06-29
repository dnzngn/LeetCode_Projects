/*
 * LeetCode #042 - Trapping Rain Water
 * https://leetcode.com/problems/trapping-rain-water/description/?envType=study-plan-v2&envId=top-interview-150
 * Difficulty: Hard
 */

#include <iostream>
#include <vector>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    int solve(vector<int>& height) {

        int n = height.size();

        int left = 0, right = n-1;
        int left_max = 0 , right_max = 0;
        int total = 0;

        while(left < right){
            left_max = max(left_max, height[left]);
            right_max = max(right_max, height[right]);

            if(left_max < right_max){
                total += left_max - height[left];
                left++;
            } else {
                total += right_max - height[right];
                right--;
            }

        }

        return total;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p042 {
void test() {
    Solution sol;

    vector<int> nums0 = {3, 0, 2};
    cout << "Test 0: " << sol.solve(nums0) << " (expected: 2)" << endl;
    
    vector<int> nums1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Test 1: " << sol.solve(nums1) << " (expected: 6)" << endl;

    vector<int> nums2 = {4,2,0,3,2,5};
    cout << "Test 2: " << sol.solve(nums2) << " (expected: 9)" << endl;
}
REGISTER_PROBLEM(42, "Trapping Rain Water")
}