/*
 * LeetCode #205 - Isomorphic Strings
 * https://leetcode.com/problems/isomorphic-strings
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
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char,char> st;
        unordered_map<char,char> ts;

        for (int i = 0; i < (int)s.size(); ++i) {
            char a = s[i], b = t[i];

            if (st.count(a) && st[a] != b) return false;
            if (ts.count(b) && ts[b] != a) return false;

            st[a] = b;
            ts[b] = a;
        }
        return true;
    }
};

/* class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            cout << "Length mismatch\n";
            return false;
        }

        unordered_map<char,char> st;
        unordered_map<char,char> ts;

        for (int i = 0; i < (int)s.size(); ++i) {
            char a = s[i], b = t[i];

            cout << "\n--- Index " << i << " ---\n";
            cout << "s[" << i << "] = '" << a << "' , "
                 << "t[" << i << "] = '" << b << "'\n";

            // s -> t kontrolü
            if (st.count(a)) {
                cout << "st['" << a << "'] already mapped to '"
                     << st[a] << "'\n";
                if (st[a] != b) {
                    cout << "❌ Conflict: '" << a << "' cannot map to '"
                         << b << "'\n";
                    return false;
                }
            } else {
                cout << "Mapping '" << a << "' -> '" << b << "'\n";
                st[a] = b;
            }

            // t -> s kontrolü
            if (ts.count(b)) {
                cout << "ts['" << b << "'] already mapped to '"
                     << ts[b] << "'\n";
                if (ts[b] != a) {
                    cout << "❌ Conflict: '" << b << "' cannot map back to '"
                         << a << "'\n";
                    return false;
                }
            } else {
                cout << "Mapping '" << b << "' -> '" << a << "'\n";
                ts[b] = a;
            }

            // mevcut map’leri yazdır
            cout << "Current mappings (s -> t): ";
            for (auto& [k, v] : st)
                cout << k << "->" << v << " ";
            cout << "\n";

            cout << "Current mappings (t -> s): ";
            for (auto& [k, v] : ts)
                cout << k << "->" << v << " ";
            cout << "\n";
        }

        cout << "\n✅ Strings are isomorphic\n";
        return true;
    }
}; */


// ==================== LEETCODE SOLUTION END ====================

namespace p205 {
void test() {
    Solution sol;
    
    string s = {"egg"};
    string t = {"add"};
    
    bool res = sol.isIsomorphic(s,t);
    
    cout << "\n===========================\n";
    cout << "Test 1: " << boolalpha << res << " expected true" << '\n';

    string s1 = {"foo"};
    string t1 = {"bar"};
    
    bool res1 = sol.isIsomorphic(s1,t1);
    
    cout << "\n===========================\n";
    cout << "Test 2: " << boolalpha << res1 << " expected false" << '\n';


    string s2 = {"paper"};
    string t2 = {"title"};
    
    bool res2 = sol.isIsomorphic(s2,t2);
    
    cout << "\n===========================\n";
    cout << "Test 3: " << boolalpha << res2 << " expected true" << '\n';


}
REGISTER_PROBLEM(205, "Isomorphic Strings")
}
