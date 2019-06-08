/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

/*
easy
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        deque<string> dq;
        int pos = 0;
        string r;
        while (pos < path.size())
        {
            if (path[pos] == '.' && pos + 1 < path.size() && path[pos + 1] == '.' && (pos + 2 == path.size() || path[pos + 2] == '/'))
            {
                pos += 2;
                if (!dq.empty())
                    dq.pop_back();
            }
            else if (path[pos] == '.' && (pos + 1 == path.size() || path[pos + 1] == '/') || path[pos] == '/')
                ++pos;
            else
            {
                string str;
                while (pos < path.size() && path[pos] != '/')
                    str += path[pos++];
                dq.push_back(str);
            }
        }
        while (!dq.empty())
        {
            r += '/';
            r += dq.front();
            dq.pop_front();
        }
        if (r.empty())
            r = "/";
        return r;
    }
};
