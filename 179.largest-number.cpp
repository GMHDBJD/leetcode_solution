/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

/*
lhs+rhs<rhs+lhs
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(const string& lhs,const string& rhs)
    {
        return lhs+rhs > rhs+lhs;
    }
    string largestNumber(vector<int>& nums) {
        string r;
        vector<string> v;
        for (auto &&i : nums)
        {
            v.push_back(to_string(i));
        }
        sort(v.begin(),v.end(),cmp);
        for (auto &&i : v)
        {
            r+=i; 
        }
        return r.front()=='0'?"0":r;
    }
};
