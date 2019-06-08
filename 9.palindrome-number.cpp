/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

/*
many solution
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    bool isPalindrome(int x)
    {
        string str = to_string(x);
        if (str != "0" && str.back() == '0')
            return false;
        string r_str = str;
        reverse(r_str.begin(), r_str.end());
        return r_str == str;
    }
};
