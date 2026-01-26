/*
 * LeetCode #73 - Set Matrix Zeroes
 * https://leetcode.com/problems/set-matrix-zeroes/
 * Difficulty: Medium
 */

#include <iostream>
#include <vector>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = (int)matrix.size();
        int cols = (int)matrix[0].size();

        auto x_matrix = matrix;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){

                int top = 0, bottom = rows - 1;
                int left = 0, right = cols - 1;
                
                if(x_matrix[i][j] == 0){
                    while(top != rows){
                        //cout << "rows: " << i << '\t' << top << '\n';
                        matrix[top][j] = 0;
                        top++;
                    }
                    while (left != cols)
                    {
                        //cout << "column: " << left << '\t' << j << '\n';
                        matrix[i][left] = 0;
                        left++;
                    }         
                }      
            }
        }
    }
};

// ==================== LEETCODE SOLUTION END ====================

namespace p073 {
void test() {
    Solution sol;
    
    vector<vector<int>> matrix = {{1,1,1},
                                {1,0,1},
                                {1,1,1}};

    int rows = (int)matrix.size();
    int cols = (int)matrix[0].size();


    sol.setZeroes(matrix);
    
    cout << "Test 1: \n[[";

    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            cout << matrix[i][j] << ',';
        }
        cout << "]\n";
    }

    cout << "] (expected: \n[[1,0,1]\n[0,0,0]\n[1,0,1]])" << endl;

    cout << "\n===========================\n";
    vector<vector<int>> matrix1 = {
                                    {0,1,2,0},
                                    {3,4,5,2},
                                    {1,3,1,5}};

    sol.setZeroes(matrix1);
    
    cout << "Test 2: \n[[";

    for(int i = 0; i < matrix1.size(); i++){
        for(int j = 0; j < matrix1[0].size(); j++){
            cout << matrix1[i][j] << ',';
        }
        cout << "]\n";
    }

    cout << "] (expected: \n[[0,0,0,0]\n[0,4,5,0]\n[0,3,1,0]])" << endl;
}
REGISTER_PROBLEM(73, "Set Matrix Zeroes")
}
