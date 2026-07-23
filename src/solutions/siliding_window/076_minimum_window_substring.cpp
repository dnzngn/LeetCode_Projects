/*
 * LeetCode #076 - Minimum Window Substring
 * https://leetcode.com/problems/minimum-window-substring/?envType=study-plan-v2&envId=top-interview-150
 * Difficulty: Hard
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <climits>

#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();

        int left = 0;

        int formed = 0;

        int best = INT_MAX;
        int start_pos = 0;

        unordered_map<char,int> window;
        string result;

        if (m < n) return result;

        // 1) İhtiyaç tablosu
        unordered_map<char,int> need;

        for (const char& c : t) {
            need[c]++;
        }

        int required = need.size(); // kaç çeşit eleman var
        

        for (int right = 0; right < m; right++) {
            
            window[s[right]]++;

            /// ÖNEMLİ!!: Bu şekilde kullanırsan need'e ekleme yapılıyor. 
            // find fonksiyonu ile kullan ve aram yap !!!!
            // yazarken operator[], okurken find/count
            /* if(window[s[right]] == need[s[right]])
                formed++;
             */

            auto it = need.find(s[right]);

            if (it != need.end() && window[s[right]] == it->second) 
                formed++;

            while (formed == required) {

                int len = right - left + 1;

                // SORU 2: burada uzunluk nasıl hesaplanır?
                if (len < best) {
                    best = len; 
                    start_pos = left;
                }

                // SORU 3: soldan daraltmak ne demek?
                window[s[left]]--;

                auto itd = need.find(s[left]);
                if (itd != need.end() && window[s[left]] < itd->second) 
                    formed--;

                left++;
                
            }
        }

        result = s.substr(start_pos, best);


        return best == INT_MAX ? "" : result;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p076 {
void test() {
    Solution sol;

    string s0{"ADOBECODEBANC"};
    string t0{"ABC"};
    auto ans0 = sol.minWindow(s0,t0);

    cout << "\nTest 1:\n[";
    for(const auto a : ans0){
        cout << a;
    }
    cout << "] (expected: [BANC])\n";

    cout << "\n============================================\n";

    string s1{"a"};
    string t1{"a"};

    auto ans1 = sol.minWindow(s1,t1);

    cout << "\nTest 2:\n[";
    for(const auto a : ans1){
        cout << a;
    }
    cout << "] (expected: [a])\n";


    cout << "\n============================================\n";

    string s2{"a"};
    string t2{"b"};

    auto ans2 = sol.minWindow(s2,t2);

    cout << "\nTest 3:\n[";
    for(const auto a : ans2){
        cout << a;
    }
    cout << "] (expected: [])\n";

    cout << "\n============================================\n";

    string s3{"cabwefgewcwaefgcf"};
    string t3{"cae"};

    auto ans3 = sol.minWindow(s3,t3);

    cout << "\nTest 4:\n[";
    for(const auto a : ans3){
        cout << a;
    }
    cout << "] (expected: [cwae])\n";

    cout << "\n============================================\n";


}
REGISTER_PROBLEM(76, "Minimum Window Substring")
}
