/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

/*
bfs
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        wordList.insert(wordList.begin(), beginWord);
        queue<pair<int, int>> q;
        vector<bool> v(wordList.size());
        map<int, set<int>> m;
        for (int i = 0; i < wordList.size(); ++i)
            for (int j = i + 1; j < wordList.size(); ++j)
            {
                if (valid(wordList[i], wordList[j]))
                {
                    m[i].insert(j);
                    m[j].insert(i);
                }
            }
        q.push({0, 1});
        v[0] = true;
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            int pos = p.first;
            int cnt = p.second;
            if (wordList[pos] == endWord)
                return cnt;
            for (auto &&i : m[pos])
            {
                if (!v[i])
                {
                    v[i] = true;
                    q.push({i, cnt + 1});
                }
            }
        }
        return 0;
    }
    bool valid(const string &lhs, const string &rhs)
    {
        bool flag = true;
        for (int i = 0; i < lhs.size(); ++i)
        {
            if (lhs[i] == rhs[i])
                continue;
            else
            {
                if (flag)
                    flag = false;
                else
                    return false;
            }
        }
        return true;
    }
};
