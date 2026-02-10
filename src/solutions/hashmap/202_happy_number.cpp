/*
 * LeetCode #202 - Happy Number
 * https://leetcode.com/problems/happy-number
 * Difficulty: Easy
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <math.h>

#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    bool isHappy(int n) {

        unordered_set<int> seen;

        while (n != 1) {

            // Daha önce bu sayıya geldiysek döngü var
            if (seen.count(n)) {
                return false;
            }
            seen.insert(n);

            int sum = 0;

            // Rakamların kareleri toplamı
            while (n > 0) {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }

            n = sum;
        }

        return true;
    }
};

// ==================== LEETCODE SOLUTION END ====================

namespace p202 {
void test() {
    Solution sol;
    
    int nums1 = 19;
    auto res1 = sol.isHappy(nums1);
    cout << "Test 1: " << boolalpha << res1 << " expected true";

    cout << "\n===========================\n";
    
    int nums2 = 2;
    auto res2 = sol.isHappy(nums2);
    cout << "Test 2: " << boolalpha << res2 << " expected false";

    cout << "\n===========================\n";

    int nums3 = 1;
    auto res3 = sol.isHappy(nums3);
    cout << "Test 3: " << boolalpha << res3 << " expected true";

    cout << "\n===========================\n";

    int nums4 = 10;
    auto res4 = sol.isHappy(nums4);
    cout << "Test 4: " << boolalpha << res4 << " expected true";

    cout << "\n===========================\n";

    int nums5 = 7;
    auto res5 = sol.isHappy(nums5);
    cout << "Test 5: " << boolalpha << res5 << " expected true";

    cout << "\n===========================\n";

    int nums6 = 4;
    auto res6 = sol.isHappy(nums6);
    cout << "Test 6: " << boolalpha << res6 << " expected false";

    cout << "\n===========================\n";

    int nums7 = 1111111;
    auto res7 = sol.isHappy(nums7);
    cout << "Test 7: " << boolalpha << res7 << " expected true";
    
}
REGISTER_PROBLEM(202, "Happy Number")
}
