/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 */

/*
easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        unordered_map<string,int> ma;
        vector<string> v;
        for (int i = 0; i + 10 <= s.size(); ++i)
        {
            string str = s.substr(i, 10);
            ma[str]++;
            if(ma[str]==2)
                v.push_back(str);
        }
        return v;
    }
};
