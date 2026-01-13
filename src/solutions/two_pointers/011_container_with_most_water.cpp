/*
 * LeetCode #11 - Container With Most Water
 * https://leetcode.com/problems/container-with-most-water/
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
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;

        while (left < right) {
            int currentHeight = min(height[left], height[right]);
            int currentWidth = right - left;
            int currentArea = currentHeight * currentWidth;

            maxWater = max(maxWater, currentArea);

            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }

        return maxWater;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p011 {
void test() {
    Solution sol;
    
    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Test 1: " << sol.maxArea(height1) << " (expected: 49)" << endl;
    
    vector<int> height2 = {1, 1};
    cout << "Test 2: " << sol.maxArea(height2) << " (expected: 1)" << endl;
}
REGISTER_PROBLEM(11, "Container With Most Water")
}
