/*
 * LeetCode #228 - Summary Ranges
 * https://leetcode.com/problems/summary-ranges/description/?envType=study-plan-v2&envId=top-interview-150
 * Difficulty: Easy
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();
        int start_pos = 0;

        for (int i = 0; i < n; i++) {                    // i < n  (i < n-1 değil)
            bool is_break = (i == n - 1) ||              // son eleman → daima kapat
                            static_cast<long long>(nums[i]) + 1 != nums[i + 1];

            if (is_break) {
                if (start_pos == i) {
                    result.push_back(to_string(nums[start_pos]));
                } else {
                    result.push_back(to_string(nums[start_pos]) + "->" + to_string(nums[i]));
                }
                start_pos = i + 1;                       // yeni run i+1'de başlar
            }
            // is_break false → hiçbir şey yapma, run devam ediyor
        }

        return result;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p228 {
void test() {
    Solution sol;
    
    vector<int> nums1 = {0,1,2,4,5,7};

    auto ans1 = sol.summaryRanges(nums1);

    cout << "\nTest 1:\n[";
    for(const auto a : ans1){
        cout << a << ", ";
    }
    cout << "] (expected: [0->2, 4->5, 7])\n";


    cout << "\n============================================\n";
    
    vector<int> nums2 = {0,2,3,4,6,8,9};
    auto ans2 = sol.summaryRanges(nums2);
    
    cout << "\nTest 2:\n[";
    for(const auto a : ans2){
        cout << a<< ", ";
    }
    cout << "] (expected: [0, 2->4, 6, 8->9])\n";

    cout << "\n============================================\n";
/* 
    vector<int> nums3 = {2,2,2,2,2,2,2};
    auto ans3 = sol.summaryRanges(nums3);

    cout << "\nTest 3:\n[";
    for(const auto a : ans3){
        cout << a<< ", ";
    }
    cout << "] (expected: [2])\n";

    cout << "\n============================================\n"; */
}
REGISTER_PROBLEM(228, "Summary Ranges")
}
