/*
 * LeetCode #452 - Minimum Number of Arrows to Burst Balloons
 * https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/?envType=study-plan-v2&envId=top-interview-150
 * Difficulty: Medium
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end(),
                  [](const vector<int>& a, const vector<int>& b) {
                      return a[1] < b[1];        // end'e göre artan
                  });

        for(const auto &p : points){
            cout << p[0] << '\t' << p[1] << '\n';
        }

        int arrows = 1;
        int arrow_pos = points[0][1];            // ilk ok: en erken biten balonun ucu

        for (int i = 1; i < (int)points.size(); i++) {
            if (points[i][0] > arrow_pos) {      // mevcut ok bu balonu delmiyor
                arrows++;
                arrow_pos = points[i][1];        // yeni oku bu balonun ucuna koy
            }
            // else: ok zaten deliyor → hiçbir şey yapma
        }

        return arrows;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p452 {
void test() {
    Solution sol;
    
    vector<vector<int>> points1 = {{10,16},{2,8},{1,6},{7,12}};

    auto ans1 = sol.findMinArrowShots(points1);

    
    cout << "\nTest 1: " << ans1 << " (expected: 2)\n";


    cout << "\n============================================\n";
    
   vector<vector<int>> points2 = {{1,2},{3,4},{5,6},{7,8}};

    auto ans2 = sol.findMinArrowShots(points2);
    
    
    cout << "\nTest 2: " << ans2 << " (expected: 4)\n";

    cout << "\n============================================\n";


    vector<vector<int>>  points3 = {{1,2},{2,3},{3,4},{4,5}};
    auto ans3 = sol.findMinArrowShots(points3);

    cout << "\nTest 3: " << ans3 << " (expected: 2)\n";

    cout << "\n============================================\n";

}

REGISTER_PROBLEM(452, "Minimum Number of Arrows to Burst Balloons")
}
