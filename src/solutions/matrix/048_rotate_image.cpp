/*
 * LeetCode #36 - Valid Sudoku
 * https://leetcode.com/problems/rotate-image/
 * Difficulty: Medium
 */

#include <iostream>
#include <vector>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        auto x = matrix;

        auto s = x.size()-1;
        

        for(int i = 0; i < x.size(); i++){
            for(int j = 0; j < x.size(); j++){
                matrix[i][j] = x[s-j][i];
            }
        }
    

    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p048 {
void test() {
    Solution sol;
    
    vector<vector<int>> matrix = {
                                {5,1,9,11},
                                {2,4,8,10},
                                {13,3,6,7},
                                {15,14,12,16}};

    cout << "\n===========================\n";
    cout << "Test 1: " << '\n';

    sol.rotate(matrix);
    
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix.size(); j++){
            cout << matrix[i][j] << '\t';
        }
        cout << '\n';
    }
}
REGISTER_PROBLEM(48, "Rotate Image")
}
