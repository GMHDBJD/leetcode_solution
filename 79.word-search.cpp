/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

/*
no extra space
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (board.empty())
            return false;
        vector<vector<bool>> v(board.size(), vector<bool>(board.front().size(), false));
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board.front().size(); ++j)
                if (dfs(board, word, i, j, 0))
                    return true;
        return false;
    }
    bool dfs(vector<vector<char>> &board, string word, int x, int y, int pos)
    {
        if (pos == word.size())
            return true;
        if (x < 0 || y < 0 || x == board.size() || y == board.front().size())
            return false;
        if (board[x][y] != word[pos])
            return false;
        board[x][y] ^= 256;
        if (dfs(board, word, x - 1, y, pos + 1))
            return true;
        if (dfs(board, word, x + 1, y, pos + 1))
            return true;
        if (dfs(board, word, x, y - 1, pos + 1))
            return true;
        if (dfs(board, word, x, y + 1, pos + 1))
            return true;
        board[x][y] ^= 256;
        return false;
    }
};
