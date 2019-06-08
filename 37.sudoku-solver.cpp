/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

/*
dfs
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    void solveSudoku(vector<vector<char>> &board)
    {
        set<char> row[9], col[9], block[9];
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                char n = board[i][j];
                if (n == '.')
                    continue;
                row[i].insert(n);
                col[j].insert(n);
                block[j / 3 + i / 3 * 3].insert(n);
            }
        }
        vector<vector<char>> temp = board;
        dfs(0, 0, row, col, block, board, temp);
    }
    bool dfs(int x, int y, set<char> *row, set<char> *col, set<char> *block, vector<vector<char>> &board, vector<vector<char>> &temp)
    {
        int next_x = -1, next_y = -1;
        if (x == 8)
        {
            next_x = 0;
            next_y = y + 1;
        }
        else
        {
            next_x = x + 1;
            next_y = y;
        }
        if (temp[y][x] != '.')
        {
            if (x == 8 && y == 8)
                return true;
            else
                return dfs(next_x, next_y, row, col, block, board, temp);
        }
        for (char i = '1'; i <= '9'; ++i)
        {
            if (row[y].find(i) != row[y].end())
                continue;
            if (col[x].find(i) != col[x].end())
                continue;
            if (block[x / 3 + y / 3 * 3].find(i) != block[x / 3 + y / 3 * 3].end())
                continue;
            row[y].insert(i);
            col[x].insert(i);
            block[x / 3 + y / 3 * 3].insert(i);
            board[y][x] = i;
            if (x == 8 && y == 8)
                return true;
            else
            {
                if (dfs(next_x, next_y, row, col, block, board, temp))
                    return true;
                row[y].erase(i);
                col[x].erase(i);
                block[x / 3 + y / 3 * 3].erase(i);
                board[y][x] = '.';
            }
        }
        return false;
    }
};
