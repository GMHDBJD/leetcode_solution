/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int start = 0, l = 0, r = 0;
        int st = 0;
        while (start < s.size())
        {
            if (s[start] == ' ')
            {
                ++start;
            }
            else
            {
                l = start;
                ++start;
                while (start < s.size() && s[start] != ' ')
                    ++start;
                r = start - 1;
                while (r > l)
                    swap(s[l++], s[r--]);
            }
        }
        l = 0;
        r = s.size() - 1;
        while (r > l)
            swap(s[l++], s[r--]);
        bool word = true;
        bool first = true;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != ' ')
            {
                first = false;
                if (!word)
                    s[st++] = ' ';
                s[st++] = s[i];
                word = true;
            }
            else
            {
                if (word && !first)
                    word = false;
                continue;
            }
        }
        return s.substr(0, st);
    }
};
