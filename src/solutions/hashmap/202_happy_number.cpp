/*
 * LeetCode #202 - Happy Number
 * https://leetcode.com/problems/happy-number
 * Difficulty: Easy
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>

#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    bool isHappy(int n) {

        vector<int> digits;
        unordered_map<int, int> map_n;
        
        int sum{0};

        cout << n/10 << '\n';
       
        if(n/10 < 1){
            sum = pow(n%10,2);
        } else {

            
            cout << "n:\t" << n << '\n';
            cout << "sum:\t" << sum << '\n';
        
            digits.push_back(n%10);
            
            while (n > 0){
                cout << "Hey\n";
                n = n/10;
                digits.push_back(n%10);
            }

            
            
            for(int i =0; i<digits.size()-1; i++){
                //cout <<"From vec: " << digits[i] << '\t';
                sum += pow(digits[i],2);
            }

            

            n = sum;
            

            cout << "sum:\t" << sum << '\n';
            cout << "n:\t" << n << '\n';
        }

    
        cout << "sum:\t" << sum << '\n';
        
        
        return n == 1;
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
}
REGISTER_PROBLEM(202, "Happy Number")
}
