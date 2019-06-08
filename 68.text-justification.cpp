/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 */

/*
better nested loop
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> r;
        bool first = true;
        vector<string> temp;
        int l = 0;
        int pos = 0;
        while (pos < words.size())
        {
            if (first)
            {
                first = false;
                temp.push_back(words[pos]);
                l += words[pos].length();
                ++pos;
            }
            else if (words[pos].length() + l + 1 <= maxWidth)
            {
                temp.push_back(words[pos]);
                l += words[pos].length() + 1;
                ++pos;
            }
            else
            {
                r.push_back(temp.front());
                if (temp.size() == 1)
                {
                    r.back() += string(maxWidth - l, ' ');
                }
                else
                {
                    int a = temp.size() - 1;
                    int b = maxWidth - l;
                    int c = b / a;
                    int d = b % a;
                    for (int i = 1; i < temp.size(); ++i)
                    {
                        r.back() += string(c + 1, ' ');
                        if (d)
                        {
                            --d;
                            r.back() += ' ';
                        }
                        r.back() += temp[i];
                    }
                }
                temp.clear();
                first = true;
                l = 0;
            }
        }
        if (!temp.empty())
        {
            r.push_back(temp.front());
            for (int i = 1; i < temp.size(); ++i)
            {
                r.back() += ' ';
                r.back() += temp[i];
            }
            r.back() += string(maxWidth - l, ' ');
        }
        return r;
    }
};
