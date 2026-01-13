/*
 * LeetCode #121 - Best Time to Buy and Sell Stock
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * Difficulty: Easy
 */

#include <iostream>
#include <vector>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); ++i) {
            int profit = prices[i] - minPrice;
            if (profit > maxProfit) {
                maxProfit = profit;
            }
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
        }

        return maxProfit;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p121 {
void test() {
    Solution sol;
    
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Test 1: " << sol.maxProfit(prices1) << " (expected: 5)" << endl;
    
    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << "Test 2: " << sol.maxProfit(prices2) << " (expected: 0)" << endl;
}
REGISTER_PROBLEM(121, "Best Time to Buy and Sell Stock")
}
