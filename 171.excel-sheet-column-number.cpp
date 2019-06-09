/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */

/*
easy
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int titleToNumber(string s)
    {
        int result=0;
        for (auto &&i : s)
        {
           result=26*result+(i-'A')+1; 
        }
        return result;
    }
};
