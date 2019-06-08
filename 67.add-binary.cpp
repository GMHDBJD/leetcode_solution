/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

/*
same as bignum add
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int c = 0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int l = 0, r = 0;
        string str;
        while (l < a.size() || r < b.size() || c)
        {
            int sum = c;
            if (l < a.size())
            {
                sum += a[l] - '0';
                ++l;
            }
            if (r < b.size())
            {
                sum += b[r] - '0';
                ++r;
            }
            c = sum / 2;
            str += '0' + (sum % 2);
        }
        reverse(str.begin(), str.end());
        return str;
    }
};
