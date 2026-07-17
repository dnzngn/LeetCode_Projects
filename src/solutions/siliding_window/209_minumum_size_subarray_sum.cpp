/*
 * LeetCode #209 - Minumum Size Subarray Sum
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/?envType=study-plan-v2&envId=top-interview-150
 * Difficulty: Medium
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        long long sum = 0;                // [left, right] penceresindeki toplam
        int best = INT8_MAX;             // şimdiye kadarki en kısa uzunluk

        long long total = 0;
        for (int x : nums) total += x;
        std::cout << "n=" << n << "  target=" << target
                << "  toplam(dizi)=" << total << "\n";

        for (int right = 0; right < n; right++) {
            sum += nums[right];         // pencereyi sağdan büyüt

            // SORU 1: while koşuluna ne yazılır?
            // "Pencere toplamı hâlâ geçerli olduğu sürece soldan daralt."
            // Geçerlilik koşulu neydi — == mı, >= mı?
            while (sum >= target) {
                int len = right - left + 1;

                if (len < best) {
                    std::cout << "yeni best=" << len
                            << "  pencere=[" << left << ".." << right << "]"
                            << "  sum=" << sum << "\n";   // ← her iyileşmeyi izle
                }

                // SORU 2: burada uzunluk nasıl hesaplanır?
                // [left, right] aralığının eleman sayısı, iki index cinsinden.
                best = min(best, len);

                // SORU 3: soldan daraltmak ne demek?
                // sum'dan hangi elemanı çıkarıp left'i nereye taşırsın?
                sum -= nums[left];
                left++;
                
            }
        }

        // hiç geçerli pencere bulunamadıysa 0 döndürülür
        return best == INT8_MAX ? 0 : best;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p209 {
void test() {
    Solution sol;

    int target0{7};
    vector<int> nums0{2,3,1,2,4,3};

    cout << "\nTest 1:\n" << sol.minSubArrayLen(target0,nums0) << " (expected: 2)\n";

    cout << "\n============================================\n";

    int target1{4};
    vector<int> nums1{1,4,4};

    cout << "\nTest 2: " << sol.minSubArrayLen(target1,nums1) << " (expected: 1)\n";

    cout << "\n============================================\n";

    int target2{11};
    vector<int> nums2{1,1,1,1,1,1,1,1};

    cout << "\nTest 3: " << sol.minSubArrayLen(target2,nums2) << " (expected: 0)\n";

    cout << "\n============================================\n";

    int target3{11};
    vector<int> nums3{1,2,3,4,5};

    cout << "\nTest 4: " << sol.minSubArrayLen(target3,nums3) << " (expected: 3)\n";

    cout << "\n============================================\n";

}
REGISTER_PROBLEM(209, "Minumum Size Subarray Sum")
}
