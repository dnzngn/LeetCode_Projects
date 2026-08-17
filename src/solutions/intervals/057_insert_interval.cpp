/*
 * LeetCode #057 - Insert Intervals
 * https://leetcode.com/problems/insert-interval/?envType=study-plan-v2&envId=top-interview-150
 * Difficulty: Medium
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> result;

        int n = intervals.size();
        int i = 0;
        int ns = newInterval[0];
        int ne = newInterval[1];



        while (i < n && intervals[i][1] < ns){
            cout << "To Left\n";
            // result.push_back(intervals[i]);
            result.push_back(std::move(intervals[i])); // intervals non-const olduğu için bu şekilde run time verimliliği

            i++;
        }

        while (i < n && intervals[i][0] <= ne){
            cout << "In middle\n";
            ns = min(ns, intervals[i][0]);
            ne = max(ne, intervals[i][1]);
            
            i++;
        }

        result.push_back({ns,ne});
    
        while (i < n){
            cout << "To Right\n";
            //result.push_back(intervals[i]);
            result.push_back(std::move(intervals[i]));

            i++;
        }
        
        

        return result;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p057 {
void test() {
    Solution sol;
    
    vector<vector<int>> nums1 = {{1,3},{6,9}};
    vector<int> newInt1 = {2,5};

    auto ans1 = sol.insert(nums1,newInt1);

    cout << "\nTest 1:\n[";
    for(const auto rows : ans1){
        cout << "[";
        for (const auto col : rows)
            cout << col << ",";
        cout << "]";
    }
    cout << "] (expected: [[1,5],[6,9]])\n";


    cout << "\n============================================\n";
    
    vector<vector<int>> nums2 = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> newInt2 = {4,8};

    auto ans2 = sol.insert(nums2,newInt2);
    
    cout << "\nTest 2:\n[";
    for(const auto rows : ans2){
        cout << "[";
        for (const auto col : rows)
            cout << col << ",";
        cout << "]";
    }
    cout << "] (expected: [[1,2],[3,10],[12,16])\n";

    cout << "\n============================================\n";
}

REGISTER_PROBLEM(57, "Insert Intervals")
}
