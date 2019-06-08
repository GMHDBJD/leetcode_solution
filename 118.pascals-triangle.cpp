/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

/*
easy
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> r;
        if (!numRows)
            return r;
        r.push_back({1});
        for (int i = 2; i <= numRows; ++i)
        {
            vector<int> v = {1};
            for (int j = 0; j + 1 < r.back().size(); ++j)
                v.push_back(r.back()[j] + r.back()[j + 1]);
            v.push_back(1);
            r.push_back(v);
        }
        return r;
    }
};
