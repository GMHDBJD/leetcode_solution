/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

/*
hashmap
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        set<char> row[9];
        set<char> col[9];
        set<char> block[9];
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                char n = board[i][j];
                if (n == '.')
                    continue;
                if (row[i].find(n) != row[i].end())
                    return false;
                else
                    row[i].insert(n);
                if (col[j].find(n) != col[j].end())
                    return false;
                else
                    col[j].insert(n);
                if (block[j / 3 + i / 3 * 3].find(n) != block[j / 3 + i / 3 * 3].end())
                    return false;
                else
                    block[j / 3 + i / 3 * 3].insert(n);
            }
        }
        return true;
    }
};
