/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

/*
stupid
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    string intToRoman(int num)
    {
        string r;
        int n = num / 1000;
        num %= 1000;
        for (int i = 0; i < n; ++i)
        {
            r += "M";
        }

        n = num / 900;
        num %= 900;
        for (int i = 0; i < n; ++i)
        {
            r += "CM";
        }

        n = num / 500;
        num %= 500;
        for (int i = 0; i < n; ++i)
        {
            r += "D";
        }

        n = num / 400;
        num %= 400;
        for (int i = 0; i < n; ++i)
        {
            r += "CD";
        }

        n = num / 100;
        num %= 100;
        for (int i = 0; i < n; ++i)
        {
            r += "C";
        }

        n = num / 90;
        num %= 90;
        for (int i = 0; i < n; ++i)
        {
            r += "XC";
        }

        n = num / 50;
        num %= 50;
        for (int i = 0; i < n; ++i)
        {
            r += "L";
        }

        n = num / 40;
        num %= 40;
        for (int i = 0; i < n; ++i)
        {
            r += "XL";
        }

        n = num / 10;
        num %= 10;
        for (int i = 0; i < n; ++i)
        {
            r += "X";
        }

        n = num / 9;
        num %= 9;
        for (int i = 0; i < n; ++i)
        {
            r += "IX";
        }

        n = num / 5;
        num %= 5;
        for (int i = 0; i < n; ++i)
        {
            r += "V";
        }

        n = num / 4;
        num %= 4;
        for (int i = 0; i < n; ++i)
        {
            r += "IV";
        }

        n = num;
        for (int i = 0; i < n; ++i)
        {
            r += "I";
        }
        return r;
    }
};
