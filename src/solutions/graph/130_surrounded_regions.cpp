/*
 * LeetCode #130 - Surrounded Regions
 * https://leetcode.com/problems/surrounded-regions/
 * Difficulty: Medium
 */

#include <iostream>
#include <vector>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        
        int rows = board.size();
        int cols = board[0].size();
        
        for (int i = 0; i < rows; i++) {
            dfs(board, i, 0);
            dfs(board, i, cols - 1);
        }
        for (int j = 0; j < cols; j++) {
            dfs(board, 0, j);
            dfs(board, rows - 1, j);
        }
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
    
private:
    void dfs(vector<vector<char>>& board, int i, int j) {
        int rows = board.size();
        int cols = board[0].size();
        
        if (i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] != 'O')
            return;
        
        board[i][j] = '#';
        
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p130 {
void test() {
    Solution sol;
    
    vector<vector<char>> board = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };
    
    sol.solve(board);
    
    cout << "Test 1 Result:" << endl;
    for (const auto& row : board) {
        for (char c : row) cout << c << " ";
        cout << endl;
    }
}
REGISTER_PROBLEM(130, "Surrounded Regions")
}
