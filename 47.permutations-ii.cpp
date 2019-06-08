/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

/*
same as problem46
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        if (nums.empty())
            return {{}};
        vector<int> v;
        vector<vector<int>> r;
        int b = nums.size() - 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            v = nums;
            swap(v[b], v[i]);
            vector<int> temp{std::vector<int>(v.begin(), v.end() - 1)};
            for (auto &&vec : permuteUnique(temp))
            {
                vec.push_back(v[b]);
                r.push_back(vec);
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                ++i;
        }
        return r;
    }
};
