/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

/*
gready
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        long sum = 0, start = 0, gank = 0;
        for (int i = 0; i < gas.size(); ++i)
        {
            gank += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if (gank < 0)
            {
                gank = 0;
                start = i + 1;
            }
        }
        return sum < 0 ? -1 : start;
    }
};
