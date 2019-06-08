/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

/*
easy
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> v;
        vector<int> r;
        r.push_back(1);
        for (int i = 1; i <= rowIndex; ++i)
        {
            swap(v, r);
            r.clear();
            r.push_back(1);
            for (int j = 0; j + 1 < v.size(); ++j)
                r.push_back(v[j] + v[j + 1]);
            r.push_back(1);
        }
        return r;
    }
};
