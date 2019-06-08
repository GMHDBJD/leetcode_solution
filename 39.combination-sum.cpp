/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

/*
dfs
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
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
                    dfs(candidates, target, r, v, sum + i, j);
                    v.pop_back();
                }
            }
            else
                return;
        }
    }
};
