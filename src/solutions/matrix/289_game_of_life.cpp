/*
 * LeetCode #289 - Game Of Life
 * https://leetcode.com/problems/game-of-life
 * Difficulty: Medium
 */

#include <iostream>
#include <vector>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
       
        
        // Yeni state'i sakla (eski state'i korumak için)
        vector<vector<int>> new_board = board;
        
        // Her cell için
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int live_neighbors = countLiveNeighbors(board, i, j, m, n);
                
                // Kurallari uygula
                if(board[i][j] == 1) {
                    // Live cell
                    if(live_neighbors < 2) {
                        new_board[i][j] = 0;
                    } else if(live_neighbors == 2 || live_neighbors == 3) {
                        new_board[i][j] = 1;
                    } else {
                        new_board[i][j] = 0;
                    }
                } else {
                    // Dead cell
                    if(live_neighbors == 3) {
                        new_board[i][j] = 1;
                    } else {
                        new_board[i][j] = 0;
                    }
                }
            }
        }
        
        // Board'u güncelle
        board = new_board;
        
    }
    
private:
    int countLiveNeighbors(vector<vector<int>>& board, int i, int j, int m, int n) {
        int count = 0;
        
        // 8 komsu yönü (diagonal dahil)
        int directions[8][2] = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1},  {1, 0},  {1, 1}
        };
        
        for(int d = 0; d < 8; d++) {
            int ni = i + directions[d][0];
            int nj = j + directions[d][1];
            
            // Sınırlar içinde mi?
            if(ni >= 0 && ni < m && nj >= 0 && nj < n) {
                if(board[ni][nj] == 1) {
                    count++;
                }
            }
        }
        
        return count;
    }
};

// ==================== LEETCODE SOLUTION END ====================

namespace p289 {
void test() {
    Solution sol;
    
    vector<vector<int>> matrix1 = {
                                {0,1,0},
                                {0,0,1},
                                {1,1,1},
                                {0,0,0}};


    sol.gameOfLife(matrix1);
    
    cout << "Test 1: \n";

    for(int i = 0; i < matrix1.size(); i++){
        cout << "[";
        for(int j = 0; j < matrix1[0].size(); j++)
            cout << matrix1[i][j] << ", ";
        cout << "]\n";
    }

    cout << "] (expected: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]])" << endl;

    cout << "\n===========================\n";
    vector<vector<int>> matrix2 = {
                                    {1,1},
                                    {1,0}};

    sol.gameOfLife(matrix2);
    
    cout << "Test 2: \n[";

    for(int i = 0; i < matrix2.size(); i++){
        cout << "[";
        for(int j = 0; j < matrix2[0].size(); j++)
            cout << matrix2[i][j] << ", ";
        cout << "]\n";
    }

    cout << "(expected: [[1,1],[1,1]])" << endl;

    
}
REGISTER_PROBLEM(289, "Game Of Life")
}
