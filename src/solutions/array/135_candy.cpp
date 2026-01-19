/*
 * LeetCode #135 - Candy
 * https://leetcode.com/problems/candy
 * Difficulty: Hard
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = (int)ratings.size();
        if (n == 0) return 0;

        vector<int> candies(n, 1);

        // 1) Soldan sağa: rating artıyorsa candy de artmalı
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // 2) Sağdan sola: rating azalıyorsa soldaki sağdakinden fazla olmalı
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        // 3) Toplam
        long long total = 0;
        for (int c : candies) total += c;
        return (int)total;
    }
};

// ==================== LEETCODE SOLUTION END ====================

namespace p135 {
void test() {
    Solution sol;
    
    vector<int> nums1 = {1,0,2};
    auto res1 = sol.candy(nums1);
    cout << "Test 1: [" << res1 << "] (expected: [5])" << endl;
    
    vector<int> nums2 = {1,2,2};
    auto res2 = sol.candy(nums2);
    cout << "Test 2: [" << res2 << "] (expected: [4])" << endl;
}
REGISTER_PROBLEM(135, "Candy")
}
