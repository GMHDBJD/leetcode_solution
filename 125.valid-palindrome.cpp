/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

/*
easy
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int l = 0, r = s.size() - 1;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        while (l < r)
        {
            if (!isalnum(s[l]))
                ++l;
            else if (!isalnum(s[r]))
                --r;
            else
            {
                if (s[l] != s[r])
                    return false;
                ++l;
                --r;
            }
        }
        return true;
    }
};
