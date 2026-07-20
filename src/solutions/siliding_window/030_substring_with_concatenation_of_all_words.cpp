/*
 * LeetCode #30 - Substring with Concatenation of All Words
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/?envType=study-plan-v2&envId=top-interview-150
 * Difficulty: Hard
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        int k = words.size();
        int m = words[0].size();
        int L = k * m;

        vector<int> results;
        if (n < L) return results;

        // 1) İhtiyaç tablosu
        unordered_map<string_view,int> need;

        for (const string& w : words) {
            need[w]++;
        }

        // 2) Her başlangıcı dene
        for (int i = 0; i + L <= n; i++) {
            unordered_map<string_view,int> window;
            bool ok = true;
            for (int j = 0; j < k; j++) {
                string piece = s.substr(i + j*m, m);

                auto it = need.find(piece);
                if (it == need.end()) { ok = false; break; }
                if (++window[piece] > it->second) { ok = false; break; } 
            }
            if (ok) results.push_back(i);
            window.clear();
        }
        return results;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p030 {
void test() {
    Solution sol;

    string s0{"barfoothefoobarman"};
    vector<string> words0{"foo","bar"};
    auto ans0 = sol.findSubstring(s0,words0);

    cout << "\nTest 1:\n[";
    for(const auto a : ans0){
        cout << a << " ,";
    }
    cout << "] (expected: [0,9])\n";

    cout << "\n============================================\n";

    string s1{"wordgoodgoodgoodbestword"};
    vector<string> words1{"word","good","best","word"};

    auto ans1 = sol.findSubstring(s1,words1);

    cout << "\nTest 2:\n[";
    for(const auto a : ans1){
        cout << a << " ,";
    }
    cout << "] (expected: [])\n";


    cout << "\n============================================\n";

    string s2{"barfoofoobarthefoobarman"};
    vector<string> words2{"bar","foo","the"};

    auto ans2 = sol.findSubstring(s2,words2);

    cout << "\nTest 3:\n[";
    for(const auto a : ans2){
        cout << a << " ,";
    }
    cout << "] (expected: [6,9,12])\n";

    cout << "\n============================================\n";


}
REGISTER_PROBLEM(30, "Substring with Concatenation of All Words")
}
