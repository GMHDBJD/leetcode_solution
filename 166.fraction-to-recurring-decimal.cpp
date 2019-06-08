/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 */

/*
map[numerator]=index
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        string result;
        if (numerator == 0)
            return "0";
        result += (numerator > 0) ^ (denominator > 0) ? "-" : "";
        long num = labs(long(numerator));
        long den = labs(long(denominator));
        result += to_string(num / den);
        num %= den;
        map<int, int> m;
        if (num)
            result += ".";
        while (num)
        {
            if (m.count(num))
            {
                result.insert(m[num], "(");
                result += ")";
                return result;
            }
            else
            {
                m[num] = result.size();
                num *= 10;
                result += to_string(num / den);
                num %= den;
            }
        }
        return result;
    }
};
