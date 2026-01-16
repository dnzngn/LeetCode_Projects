/*
 * LeetCode #134 - Gas Station
 * https://leetcode.com/problems/gas-station/
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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        return -1;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p134 {
void test() {
    Solution sol;
    
    vector<int> nums1 = {1,2,3,4,5};
    vector<int> cost1 = {3,4,5,1,2};
    auto res1 = sol.canCompleteCircuit(nums1, cost1);
    cout << "Test 1: [" << res1 << "] (expected: 3)" << endl;
    
    /* vector<int> nums2 = {2,3,4};
    vector<int> cost2 = {3,4,3};
    auto res2 = sol.canCompleteCircuit(nums2, cost2);
    cout << "Test 2: [" << res2 << "] (expected: [-1])" << endl; */
}
REGISTER_PROBLEM(134, "Gas Station")
}
