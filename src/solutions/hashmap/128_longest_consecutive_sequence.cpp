/*
 * LeetCode #128 - Longest Consecutive Sequence
 * https://leetcode.com/problems/longest-consecutive-sequence
 * Difficulty: Medium
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        // Step 1: Dublicate'leri kaldır (unordered_set kullan)
        unordered_set<int> num_set(nums.begin(), nums.end());
        
        int max_length = 0;
        
        for(const auto num : num_set) {
            // Eğer bu sayının öncesi varsa, skip et (başlangıç değil)
            if(num_set.find(num - 1) != num_set.end()) {
                continue;
            }
            
            int current = num;
            int length = 1;
            
            while(num_set.find(current + 1) != num_set.end()) {
                current++;
                length++;
            }
            
            max_length = max(max_length, length);
        }
        
        
        return max_length;
    }
};



// ==================== LEETCODE SOLUTION END ====================

namespace p128 {
void test() {
    Solution sol;
    
    vector<int> nums1 = {100,4,200,1,3,2};
    
    int res1 = sol.longestConsecutive(nums1);
    
    cout << "Test 1: " << res1 << " expected: 4" << '\n';
    cout << "\n===========================\n";

    vector<int> nums2 = {0,3,7,2,5,8,4,6,0,1};
    
    int res2 = sol.longestConsecutive(nums2);
    
    cout << "Test 2: " << res2 << " expected: 9" << '\n';
    cout << "\n===========================\n";

    vector<int> nums3 = {1,0,1,2};
    
    int res3 = sol.longestConsecutive(nums3);
    
    cout << "Test 3: " << res3 << " expected: 3" << '\n';
    cout << "\n===========================\n";



}
REGISTER_PROBLEM(128, "Longest Consecutive Sequence")
}
