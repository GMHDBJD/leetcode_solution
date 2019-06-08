/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

/*
easy
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int c = 1;
        int pos = digits.size() - 1;
        while (c)
        {
            if (pos < 0)
            {
                c = 0;
                digits.insert(digits.begin(), 1);
            }
            else
            {
                c = (digits[pos] + 1) / 10;
                digits[pos] = (digits[pos] + 1) % 10;
            }
            --pos;
        }
        return digits;
    }
};
