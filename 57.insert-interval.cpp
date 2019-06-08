/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

/*
notice left and right can be the same
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int pos = 0;
        vector<vector<int>> v;
        while (pos < intervals.size() && intervals[pos][1] < newInterval[0])
        {
            v.push_back(intervals[pos]);
            ++pos;
        }
        while (pos < intervals.size() && intervals[pos][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[pos][0]);
            newInterval[1] = max(newInterval[1], intervals[pos][1]);
            ++pos;
        }
        v.push_back(newInterval);
        while (pos < intervals.size())
        {
            v.push_back(intervals[pos]);
            ++pos;
        }
        return v;
    }
};
