/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string convertToTitle(int n)
    {
        string s;
        while (n)
        {
            s += 'A' + (n - 1) % 26;
            n = (n - 1) / 26;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
