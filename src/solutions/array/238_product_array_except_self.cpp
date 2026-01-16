/*
 * LeetCode #238 - Product of Array Except Self
 * https://leetcode.com/problems/product-of-array-except-self/
 * Difficulty: Medium
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> result(n, 1);

        // prefix products
        int prefix = 1;
        for (int i = 0; i < n; ++i) {
            result[i] = prefix;
            prefix *= nums[i];
        }

        // suffix products
        int suffix = 1;
        for (int i = n - 1; i >= 0; --i) {
            result[i] *= suffix;
            suffix *= nums[i];
        }

        return result;
    }
};

// ==================== LEETCODE SOLUTION END ====================

namespace p238 {
void test() {
    Solution sol;
    
    vector<int> nums1 = {1,2,3,4};
    auto res1 = sol.productExceptSelf(nums1);
    cout << "Test 1: [";
    for(int a : res1){
        cout << a << ", ";
    }
    cout << "] (expected: [24,12,8,6])" << endl;

    vector<int> nums2 = {-1,1,0,-3,3};
    auto res2 = sol.productExceptSelf(nums2);
    cout << "Test 2: [";
    for(int a : res2){
        cout << a << ", ";
    }
    cout << "] (expected: [0,0,9,0,0])" << endl;

}
REGISTER_PROBLEM(238, "Product of Array Except Self")
}
