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
    int n = gas.size();
    int toplam = 0;    // tüm istasyonların toplam farkı
    int tank = 0;      // mevcut başlangıçtan itibaren tank
    int baslangic = 0; // aday başlangıç istasyonu

    for (int i = 0; i < n; i++) {
        int fark = gas[i] - cost[i];
        toplam += fark;
        tank += fark;


        // tank negatife düştü → bu aday ve arasındakiler çalışmaz
        if (tank < 0) {
          
            baslangic = i + 1;  // bir sonraki istasyondan dene
            tank = 0;           // tankı sıfırla
        }
    }

  
    if (toplam >= 0) {
  
        return baslangic;
    } else {
        return -1;
    }
}
};
// ==================== LEETCODE SOLUTION END ====================

namespace p134 {
void test() {
    Solution sol;
    

    cout << "\n============================================\n";

    vector<int> nums1 = {1,2,3,4,5};
    vector<int> cost1 = {3,4,5,1,2};
    auto res1 = sol.canCompleteCircuit(nums1, cost1);
    cout << "Test 1: [" << res1 << "] (expected: 3)" << endl;
    
    cout << "\n============================================\n";

    vector<int> nums2 = {2,3,4};
    vector<int> cost2 = {3,4,3};
    auto res2 = sol.canCompleteCircuit(nums2, cost2);
    cout << "Test 2: [" << res2 << "] (expected: [-1])" << endl;


    cout << "\n============================================\n";

    vector<int> nums3 = {0,0,0,0,2};
    vector<int> cost3 = {0,0,0,1,0};
    auto res3 = sol.canCompleteCircuit(nums3, cost3);
    cout << "Test 3: [" << res3 << "] (expected: [4])" << endl;
}
REGISTER_PROBLEM(134, "Gas Station")
}
