/*
 * LeetCode #290 - Word Pattern
 * https://leetcode.com/problems/word-pattern/
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
    bool wordPattern(string pattern, string s) {

        // 1) s'yi kelimelere ayır
        vector<string> words;
        int i = 0, n = s.size();

        while (i < n) {
            while (i < n && s[i] == ' ') i++;
            if (i >= n) break;

            int start = i;
            while (i < n && s[i] != ' ') i++;

            words.push_back(s.substr(start, i - start));
        }

        // 2) Sayılar eşit olmalı
        if (words.size() != pattern.size())
            return false;

        // 3) İki yönlü map
        unordered_map<char, string> p2w;
        unordered_map<string, char> w2p;
        for (int k = 0; k < pattern.size(); ++k) {
            char p = pattern[k];
            const string& w = words[k];

            if (p2w.count(p) && p2w[p] != w) return false;
            if (w2p.count(w) && w2p[w] != p) return false;

            p2w[p] = w;
            w2p[w] = p;
        }

        return true;
    }
};



// ==================== LEETCODE SOLUTION END ====================

namespace p290 {
void test() {
    Solution sol;
    
    string p = {"abba"};
    string s = {"dog cat cat dog"};
    
    bool res = sol.wordPattern(p,s);
    
    cout << "\n===========================\n";
    cout << "Test 1: " << boolalpha << res << " expected true" << '\n';

    string p1 = {"abba"};
    string s1 = {"dog cat cat fish"};
    
    bool res1 = sol.wordPattern(p1,s1);
    
    cout << "\n===========================\n";
    cout << "Test 2: " << boolalpha << res1 << " expected false" << '\n';


    string p2 = {"aaaa"};
    string s2 = {"dog cat cat dog"};
    
    bool res2 = sol.wordPattern(p2,s2);
    
    cout << "\n===========================\n";
    cout << "Test 3: " << boolalpha << res2 << " expected true" << '\n';


}
REGISTER_PROBLEM(290, "Word Pattern")
}
