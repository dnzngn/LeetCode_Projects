/*
 * LeetCode #068 - Text Justification
 * https://leetcode.com/problems/text-justification/description/?envType=study-plan-v2&envId=top-interview-150
 * Difficulty: Hard
 */

#include <iostream>
#include <vector>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            // --- 1. ADIM: GRUPLAMA (bu kısmı sen çözdün) ---
            // [i, j) aralığındaki kelimeler bu satıra girecek
            int j = i;
            int lineLen = 0;                 // satırdaki harflerin toplamı (boşluksuz)
            while (j < n) {
                int width = lineLen + words[j].length() + (j - i);
                if (width > maxWidth) break;
                lineLen += words[j].length();
                j++;
            }

            // --- 2. ADIM: RENDER ---
            int count = j - i;               // bu satırdaki kelime sayısı
            string line;

            // DURUM A & B: son satır VEYA tek kelime → SOLA YASLA
            if (j == n || count == 1) {
                for (int k = i; k < j; k++) {
                    if (k > i) line += " ";  // kelimeler arası tek boşluk
                    line += words[k];
                }
                // satırın geri kalanını boşlukla doldur (maxWidth'e tamamla)
                line += string(maxWidth - line.length(), ' ');
            }
            // DURUM C: normal satır → TAM YASLA
            else {
                int totalSpaces = maxWidth - lineLen;  // dağıtılacak toplam boşluk
                int gaps = count - 1;                  // boşluk yuvası sayısı
                int base = totalSpaces / gaps;         // her yuvanın tabanı
                int extra = totalSpaces % gaps;        // soldan dağıtılacak fazla

                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {                   // son kelimeden sonra boşluk yok
                        // bu yuvanın sırası (k-i): ilk 'extra' yuva bir fazla alır
                        int spaces = base + (k - i < extra ? 1 : 0);
                        line += string(spaces, ' ');
                    }
                }
            }

            result.push_back(line);
            i = j;
        }
        return result;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p068 {
void test() {
    Solution sol;

    vector<string> words0 = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth0 = 16;

    auto sol0 = sol.fullJustify(words0, maxWidth0);

    cout << "\nTest 0:\n";
    
    for (auto& line : sol0) cout << line << '\n';

    cout << "\nExpected:\nThis    is    an\nexample  of text\njustification.  " <<  endl;

    cout << "\n======================\n";

    vector<string> words1 = {"What","must","be","acknowledgment","shall","be"};
    int maxWidth1 = 16;

    auto sol1 = sol.fullJustify(words1, maxWidth1);

    cout << "\nTest 1:\n";
    
    for (auto& line : sol1) cout << line << '\n';

    cout << "\nExpected:\nWhat   must   be\nacknowledgment  \nshall be        " <<  endl;

    cout << "\n======================\n";

    vector<string> words2 = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    int maxWidth2 = 20;

    auto sol2 = sol.fullJustify(words2, maxWidth2);

    cout << "\nTest 2:\n";
    
    for (auto& line : sol2) cout << line << '\n';

    cout << "\nExpected:\nScience  is  what we\nunderstand      well\nenough to explain to\na  computer.  Art is\neverything  else  we\ndo                  "<<  endl;

}
REGISTER_PROBLEM(68, "Text Justification")
}