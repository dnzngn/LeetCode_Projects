/*
 * LeetCode #54 - Spiral Matrix
 * https://leetcode.com/problems/spiral-matrix/
 * Difficulty: Medium
 */

#include <iostream>
#include <vector>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = (int)matrix.size();
        int cols = (int)matrix[0].size();

        vector<int> spiral;
        spiral.reserve(rows * cols);

        int top = 0, bottom = rows - 1;
        int left = 0, right = cols - 1;

        while (top <= bottom && left <= right) {

            // 1) üst satır (soldan sağa)
            for (int j = left; j <= right; ++j)
                spiral.push_back(matrix[top][j]);
            ++top;

            // 2) sağ sütun (yukarıdan aşağı)
            for (int i = top; i <= bottom; ++i)
                spiral.push_back(matrix[i][right]);
            --right;

            // 3) alt satır (sağdan sola) - sadece hala geçerliyse
            if (top <= bottom) {
                for (int j = right; j >= left; --j)
                    spiral.push_back(matrix[bottom][j]);
                --bottom;
            }

            // 4) sol sütun (aşağıdan yukarı) - sadece hala geçerliyse
            if (left <= right) {
                for (int i = bottom; i >= top; --i)
                    spiral.push_back(matrix[i][left]);
                ++left;
            }
        }

        return spiral;
    }
};

// ==================== LEETCODE SOLUTION END ====================

namespace p054 {
void test() {
    Solution sol;
    
    vector<vector<int>> matrix = {
                                {1,2,3},
                                {4,5,6},
                                {7,8,9}};


    auto res1 = sol.spiralOrder(matrix);
    
    cout << "Test 1: [";

    for(int i = 0; i < res1.size(); i++){
        cout << res1[i] << ", ";
    }

    cout << "] (expected: [1,2,3,6,9,8,7,4,5])" << endl;

    cout << "\n===========================\n";
    vector<vector<int>> matrix2 = {
                                {1,2,3,4},
                                {5,6,7,8},
                                {9,10,11,12}};

    auto res2 = sol.spiralOrder(matrix2);
    
    cout << "Test 2: [";

    for(int i = 0; i < res2.size(); i++){
        cout << res2[i] << ", ";
    }

    cout << "] (expected: [1,2,3,4,8,12,11,10,9,5,6,7])" << endl;

    cout << "\n===========================\n";
    vector<vector<int>> matrix3 = {{1}};

    auto res3 = sol.spiralOrder(matrix3);
    
    cout << "Test 3: [";

    for(int i = 0; i < res3.size(); i++){
        cout << res3[i] << ", ";
    }

    cout << "] (expected: [1])" << endl;

    cout << "\n===========================\n";
    vector<vector<int>> matrix4 = {{3},{2}};

    auto res4 = sol.spiralOrder(matrix4);
    
    cout << "Test 4: [";

    for(int i = 0; i < res4.size(); i++){
        cout << res4[i] << ", ";
    }

    cout << "] (expected: [3,2])" << endl;

    cout << "\n===========================\n";
    vector<vector<int>> matrix5 = {{1,2},{3,4}};

    auto res5 = sol.spiralOrder(matrix5);
    
    cout << "Test 5: [";

    for(int i = 0; i < res5.size(); i++){
        cout << res5[i] << ", ";
    }

    cout << "] (expected: [1,2,4,3])" << endl;
}
REGISTER_PROBLEM(54, "Spiral Matrix")
}
