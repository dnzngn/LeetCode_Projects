/*
 * LeetCode #383 - Ransom Note
 * https://leetcode.com/problems/ransom-note
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
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> letters;

        for (auto c : magazine)
        {
            letters[c]++;
        }

        for (auto c : ransomNote)
        {
            auto it = letters.find(c);
            if (it == letters.end() || it->second == 0)
                return false;

            it->second--;
        }

        return true;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p383 {
void test() {
    Solution sol;
    
    string note = {"a"};
    string magazine = {"b"};
    
    bool res = sol.canConstruct(note,magazine);
    
    cout << "\n===========================\n";
    cout << "Test 1: " << boolalpha << res << " expected false" << '\n';

    string note1 = {"aa"};
    string magazine1 = {"ab"};
    
    bool res1 = sol.canConstruct(note1,magazine1);
    
    cout << "\n===========================\n";
    cout << "Test 2: " << boolalpha << res1 << " expected false" << '\n';


    string note2 = {"aa"};
    string magazine2 = {"aab"};
    
    bool res2 = sol.canConstruct(note2,magazine2);
    
    cout << "\n===========================\n";
    cout << "Test 3: " << boolalpha << res2 << " expected true" << '\n';


}
REGISTER_PROBLEM(383, "Ransom Note")
}
