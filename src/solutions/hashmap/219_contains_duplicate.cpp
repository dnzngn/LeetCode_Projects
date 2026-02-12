/*
 * LeetCode #219 - Contains Duplicate II
 * https://leetcode.com/problems/contains-duplicate-ii
 * Difficulty: Easy
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "registry.hpp"
using namespace std;
// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> seen;
        
        for(int i = 0; i < nums.size(); i++) {
            // Check if current element is already in the sliding window
            if(seen.find(nums[i]) != seen.end()) {
                return true;
            }
            
            // Add current element to the window
            seen.insert(nums[i]);
            
            // Maintain window size of at most k
            // If window exceeds k, remove the leftmost element
            if(seen.size() > k) {
                seen.erase(nums[i - k]);
            }
        }
        
        return false;
    }
};
// ==================== LEETCODE SOLUTION END ====================
namespace p219 {
void test() {
    Solution sol;
    vector<int> nums1 = {1,2,3,1};
    int k1 = 3;
    auto res1 = sol.containsNearbyDuplicate(nums1, k1);
    cout << "Test 1: [" << boolalpha << res1 << "] (expected: true)";
    cout << "\n===========================\n";
    
    vector<int> nums2 = {1,0,1,1};
    int k2 = 1;
    auto res2 = sol.containsNearbyDuplicate(nums2, k2);
    cout << "Test 2: [" << boolalpha << res2 << "] (expected: true)";
    cout << "\n===========================\n";
    
    vector<int> nums3 = {1,2,3,1,2,3};
    int k3 = 2;
    auto res3 = sol.containsNearbyDuplicate(nums3, k3);
    cout << "Test 3: [" << boolalpha << res3 << "] (expected: false)";
}
REGISTER_PROBLEM(219, "Contains Duplicate II")
}