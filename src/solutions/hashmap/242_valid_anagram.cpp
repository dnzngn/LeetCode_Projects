/*
 * LeetCode #242 - Valid Anagram
 * https://leetcode.com/problems/valid-anagram
 * Difficulty: Easy
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length())
            return false;

        int i = 0, n = s.length();
        int count = 0;

        while (i < n) {

            auto x = t.find(s[i]);

            if(x != s.npos){

                t.replace(x ,1," ");

                ++count;

                if(count == n)
                    return true;
            } else
                return false;

            ++i;
            
        }
        return false;
    }
};



// ==================== LEETCODE SOLUTION END ====================

namespace p242 {
void test() {
    Solution sol;
    
    string s = {"anagram"};
    string t = {"nagaram"};
    
    bool res = sol.isAnagram(s,t);
    
    cout << "\n===========================\n";
    cout << "Test 1: " << boolalpha << res << " expected true" << '\n';

    string s1 = {"rat"};
    string t1 = {"car"};
    
    bool res1 = sol.isAnagram(s1,t1);
    
    cout << "\n===========================\n";
    cout << "Test 2: " << boolalpha << res1 << " expected false" << '\n';

    string s2 = {"aacc"};
    string t2 = {"ccac"};
    
    bool res2 = sol.isAnagram(s2,t2);
    
    cout << "\n===========================\n";
    cout << "Test 3: " << boolalpha << res2 << " expected false" << '\n';


}
REGISTER_PROBLEM(242, "Valid Anagram")
}
