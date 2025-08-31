// https://leetcode.com/problems/sudoku-solver/?envType=daily-question&envId=2025-08-31

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        fillUp(board);
    }

    bool isValid(vector<vector<char>> &board, int &row, int &col, char &val){
        for (int i = 0; i < 9; ++i)
        {
            if (board[row][i] == val) return false;
            if (board[i][col] == val) return false;
            if (board[3*(row/3)+i/3][3 *(col/3)+i%3] == val) return false;
        }
        return true;
    }

    bool fillUp(vector<vector<char>> &board){

        for (int row = 0; row < 9; ++row)
        {
            for (int col = 0; col < 9; ++col)
            {
                if (board[row][col] == '.') {
                    for (char val = '1'; val <= '9'; ++val)
                    {
                        if (isValid(board, row, col, val)) {
                            board[row][col] = val;
                            if (fillUp(board)) return true;
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
};

int main () {
    
    return 0;
}