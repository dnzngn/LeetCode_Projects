/*
 * LeetCode #6 - Zigzag Conversion
 * https://leetcode.com/problems/zigzag-conversion
 * Difficulty: Medium
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    string convert(string s, int numRows) {
    if (numRows == 1) return s;

    vector<string> satirlar(numRows, "");
    int mevcutSatir = 0;
    int yon = 1;  // 1 = aşağı, -1 = yukarı

    cout << "Harflerin satırlara dağılımı:\n\n";

    for (int i = 0; i < s.size(); i++) {
        satirlar[mevcutSatir] += s[i];

        cout << "'" << s[i] << "' → satir " << mevcutSatir;

        // en alt veya en üst satıra ulaştıysak yön değiştir
        if (mevcutSatir == 0) {
            yon = 1;   // aşağı gitmeye başla
            cout << " (yon: asagi)";
        }
        else if (mevcutSatir == numRows - 1) {
            yon = -1;  // yukarı gitmeye başla
            cout << " (yon: yukari)";
        }

        cout << "\n";
        mevcutSatir += yon;
    }

    // satırları birleştir
    string sonuc = "";
    cout << "\nSatirlar:\n";
    for (int i = 0; i < numRows; i++) {
        cout << "Satir " << i << ": " << satirlar[i] << "\n";
        sonuc += satirlar[i];
    }

    return sonuc;
}
};

// ==================== LEETCODE SOLUTION END ====================

namespace p006 {
void test() {
    Solution sol;

    cout << "\n============================================\n";
    
    string s1("PAYPALISHIRING");
    int r1 = 3;
    auto res1 = sol.convert(s1,r1);
    /* for(int i=0; i < res1.size(); i++){
        for(int j=0; j < res1[0].size(); j++)
            cout << res1[i][j] << '\t';
        cout << '\n';
    } */
    cout << "Test 1: [" << res1 << "] (expected: PAHNAPLSIIGYIR)" << endl;
    
    
}
REGISTER_PROBLEM(006, "Zigzag Conversion")
}
