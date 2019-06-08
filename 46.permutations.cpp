/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

/*
better use in place
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        if (nums.empty())
            return {{}};
        vector<int> v;
        vector<vector<int>> r;
        int b = nums.size() - 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            v = nums;
            swap(v[b], v[i]);
            vector<int> temp(std::vector<int>(v.begin(), v.end() - 1));
            for (auto &&vec : permute(temp))
            {
                vec.push_back(v[b]);
                r.push_back(vec);
            }
        }
        return r;
    }
};
