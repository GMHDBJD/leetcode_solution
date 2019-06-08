/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 */

/*
easy
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        stringstream ss1(version1);
        stringstream ss2(version2);
        vector<int> lhs;
        vector<int> rhs;
        int l, r;
        char c;
        while (true)
        {
            ss1 >> l;
            ss2 >> r;
            if (!ss1 && !ss2)
                break;
            lhs.push_back(l);
            rhs.push_back(r);
            if (l < r)
                return -1;
            else if (l > r)
                return 1;
            ss1 >> c;
            ss2 >> c;
            l = 0;
            r = 0;
        }
        return 0;
    }
};
