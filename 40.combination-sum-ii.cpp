/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

/*
same as problem 39
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> r;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, r, {}, 0, 0);
        return r;
    }
    void dfs(vector<int> &candidates, int target, vector<vector<int>> &r, vector<int> v, int sum, int pos)
    {
        for (int j = pos; j < candidates.size(); ++j)
        {
            int i = candidates[j];
            if (sum + i <= target)
            {
                v.push_back(i);
                if (sum + i == target)
                {
                    r.push_back(v);
                    return;
                }
                else
                {
                    dfs(candidates, target, r, v, sum + i, j + 1);
                    v.pop_back();
                }
            }
            else
                return;
            while (j + 1 < candidates.size() && candidates[j] == candidates[j + 1])
                ++j;
        }
    }
};
