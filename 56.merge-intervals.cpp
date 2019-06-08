/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

/*
easy as unique
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int pos = 0;
        vector<vector<int>> r;
        sort(intervals.begin(), intervals.end());
        while (pos != intervals.size())
        {
            vector<int> v = intervals[pos];
            ++pos;
            while (pos < intervals.size() && intervals[pos][0] <= v[1])
            {
                v[1] = max(intervals[pos][1], v[1]);
                ++pos;
            }
            r.push_back(v);
        }
        return r;
    }
};
