/*
 * LeetCode #274 - H-Index
 * https://leetcode.com/problems/h-index/
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
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());
        int h = 0;

        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= i + 1) {
                h = i + 1;
            } else {
                break;
            }
        }
        return h;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p274 {
void test() {
    Solution sol;
    
    vector<int> citations1 = {3, 0, 6, 1, 5};
    cout << "Test 1: " << sol.hIndex(citations1) << " (expected: 3)" << endl;
    
    vector<int> citations2 = {1, 3, 1};
    cout << "Test 2: " << sol.hIndex(citations2) << " (expected: 1)" << endl;
}
REGISTER_PROBLEM(274, "H-Index")
}
