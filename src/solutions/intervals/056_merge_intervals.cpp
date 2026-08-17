/*
 * LeetCode #056 - Merge Intervals
 * https://leetcode.com/problems/merge-intervals/description/?envType=study-plan-v2&envId=top-interview-150
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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {}; // empty input
        std::sort(intervals.begin(), intervals.end()); // sorted

        vector<vector<int>> result;
        vector<int> current = intervals[0];

        for (int i = 1; i < (int)intervals.size(); i++) {
            int s = intervals[i][0];
            int e = intervals[i][1];

            if(s <= current[1]){
                current[1] = max(current[1], e);
            } else{

                result.push_back(current);
                
                current = intervals[i];
                
            }

        }

        result.push_back(current);

        return result;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p056 {
void test() {
    Solution sol;
    
    vector<vector<int>> nums1 = {{1,3},{2,6},{8,10},{15,18}};

    auto ans1 = sol.merge(nums1);

    cout << "\nTest 1:\n[";
    for(const auto rows : ans1){
        cout << "[";
        for (const auto col : rows)
            cout << col << ",";
        cout << "]";
    }
    cout << "] (expected: [[1,6],[8,10],[15,18]])\n";


    cout << "\n============================================\n";
    
    vector<vector<int>>  nums2 = {{1,4},{4,5}};
    auto ans2 = sol.merge(nums2);
    
    cout << "\nTest 2:\n[";
    for(const auto rows : ans2){
        cout << "[";
        for (const auto col : rows)
            cout << col << ",";
        cout << "]";
    }
    cout << "] (expected: [[1,5]])\n";

    cout << "\n============================================\n";

    vector<vector<int>>  nums3 = {{4,7},{1,4}};
    auto ans3 = sol.merge(nums3);

    cout << "\nTest 3:\n[";
    for(const auto rows : ans3){
        cout << "[";
        for (const auto col : rows)
            cout << col << ",";
        cout << "]";
    }
    cout << "] (expected: [[1,7]])\n";

    cout << "\n============================================\n";
}
REGISTER_PROBLEM(56, "Merge Intervals")
}
