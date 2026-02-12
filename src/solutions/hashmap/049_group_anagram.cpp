/*
 * LeetCode #49 - Group Anagrams
 * https://leetcode.com/problems/group-anagrams
 * Difficulty: Medium
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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // string -> anagramlar listesi
        unordered_map<string, vector<string>> map;

        for(const auto& str : strs) {
            string sorted_str = str;
            sort(sorted_str.begin(), sorted_str.end());
            
            // Aynı sorted string'e sahip kelimeleri grupla
            map[sorted_str].push_back(str);
        }
        
        vector<vector<string>> res;
        
        int group_num = 1;
        for(auto& pair : map) {
            res.push_back(pair.second);
            group_num++;
        }
        
        return res;
    }
};



// ==================== LEETCODE SOLUTION END ====================

namespace p049 {
void test() {
    Solution sol;
    
    vector<string> s1 = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> res1 = sol.groupAnagrams(s1);
    
    cout << "\n===========================\n";
    cout << "Test 1: ";
    for(const auto rs : res1){

        for (const auto r : rs)
        {
            cout << "[" << r << "], ";
        }
        

    }
    cout <<"\nexpected : [bat],[nat,tan],[ate,eat,tea]" << '\n';


    vector<string> s2 = {""};
    vector<vector<string>> res2 = sol.groupAnagrams(s2);
    
    cout << "\n===========================\n";
    cout << "Test 2: ";
    for(const auto rs : res2){

        for (const auto r : rs)
        {
            cout << "[" << r << "], ";
        }
        

    }
    cout <<"\nexpected : [ ] " << '\n';


    vector<string> s3 = {"a"};
    vector<vector<string>> res3 = sol.groupAnagrams(s3);
    
    cout << "\n===========================\n";
    cout << "Test 3: ";
    for(const auto rs : res3){

        for (const auto r : rs)
        {
            cout << "[" << r << "], ";
        }
        

    }
    cout <<"\nexpected : [a]" << '\n';

    


}
REGISTER_PROBLEM(49, "Group Anagrams")
}
