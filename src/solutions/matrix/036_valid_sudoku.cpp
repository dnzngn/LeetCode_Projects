/*
 * LeetCode #36 - Valid Sudoku
 * https://leetcode.com/problems/valid-sudoku/
 * Difficulty: Medium
 */

#include <iostream>
#include <vector>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(9, false));
        vector<vector<bool>> cols(9, vector<bool>(9, false));
        vector<vector<bool>> grids(9, vector<bool>(9, false));

        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                char cell = board[row][col];
                if (cell == '.') continue;

                int num = cell - '1';
                int grid_index = (row / 3) * 3 + (col / 3);

                if (rows[row][num] || cols[col][num] || grids[grid_index][num]) {
                    return false;
                }

                rows[row][num] = true;
                cols[col][num] = true;
                grids[grid_index][num] = true;
            }
        }

        return true;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p036 {
void test() {
    Solution sol;
    
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    
    cout << "Test 1: " << boolalpha << sol.isValidSudoku(board) << " (expected: true)" << endl;
}
REGISTER_PROBLEM(36, "Valid Sudoku")
}
