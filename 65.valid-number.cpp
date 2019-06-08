/*
 * @lc app=leetcode id=65 lang=cpp
 *
 * [65] Valid Number
 */

/*
parse
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string str;
    int pos;
    bool isNumber(string s)
    {
        str = s;
        pos = 0;
        parseSpace();
        if (lookAhead() == '-' || lookAhead() == '+')
            next();
        if ((lookAhead() < '0' || lookAhead() > '9') && lookAhead() != '.')
            return false;
        bool f1 = lookAhead() >= '0' && lookAhead() <= '9';
        parseNum();
        if (lookAhead() == '.')
        {
            next();
            bool f2 = lookAhead() >= '0' && lookAhead() <= '9';
            parseNum();
            if (!f1 && !f2)
                return false;
        }
        if (lookAhead() == 'e')
        {
            next();
            if (lookAhead() == '-' || lookAhead() == '+')
                next();
            if (lookAhead() < '0' || lookAhead() > '9')
                return false;
            parseNum();
        }
        parseSpace();
        if (pos != str.length())
            return false;
        return true;
    }
    void parseSpace()
    {
        while (lookAhead() == ' ')
            next();
    }
    char lookAhead()
    {
        if (pos == str.size())
            return '\0';
        else
            return str[pos];
    }
    void next()
    {
        if (pos < str.size())
            ++pos;
    }
    void parseNum()
    {
        while (lookAhead() >= '0' && lookAhead() <= '9')
            next();
    }
};
