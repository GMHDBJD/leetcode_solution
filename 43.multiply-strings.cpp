/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

/*
the same as add
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    string multiply(string num1, string num2)
    {
        string r;
        for (int i = 0; i < num2.size(); ++i)
        {
            string str = mul(num1, num2[i]);
            string zero(num2.size() - 1 - i, '0');
            str += zero;
            r = add(r, str);
        }
        int pos = 0;
        while (pos < r.size() - 1 && r[pos] == '0')
            ++pos;
        return r.substr(pos);
    }
    string add(string num1, string num2)
    {
        string str;
        int i = 0;
        int c = 0;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        while (i < num1.size() || i < num2.size() || c)
        {
            int s = 0;
            if (i < num1.size())
                s += num1[i] - '0';
            if (i < num2.size())
                s += num2[i] - '0';
            if (c)
                s += c;
            str += s % 10 + '0';
            c = s / 10;
            ++i;
        }
        reverse(str.begin(), str.end());
        return str;
    }
    string mul(string num1, char ch)
    {
        string str;
        int i = 0;
        int c = 0;
        reverse(num1.begin(), num1.end());
        while (i < num1.size() || c)
        {
            int s = 0;
            if (i < num1.size())
                s += (num1[i] - '0') * (ch - '0');
            if (c)
                s += c;
            str += s % 10 + '0';
            c = s / 10;
            ++i;
        }
        reverse(str.begin(), str.end());
        return str;
    }
};
