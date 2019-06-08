/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 */

/*
bfs for dis than dfs
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dis;
    vector<vector<string>> r;
    map<int, set<int>> m;
    int dist = -1;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        vector<int> d(wordList.size() + 5, -1);
        swap(dis, d);
        bfs(beginWord, endWord, wordList);
        vector<string> v;
        dfs(0, v, endWord, 0, wordList);
        return r;
    }
    void dfs(int t, vector<string> &v, string &endWord, int c, vector<string> &wordList)
    {
        if (c > dist)
            return;
        v.push_back(wordList[t]);
        if (wordList[t] == endWord)
        {
            r.push_back(v);
            v.pop_back();
            return;
        }
        for (auto i : m[t])
        {
            if (dis[i] == c + 1)
            {
                dfs(i, v, endWord, c + 1, wordList);
            }
        }
        v.pop_back();
    }
    void bfs(string beginWord, string endWord, vector<string> &wordList)
    {
        wordList.insert(wordList.begin(), beginWord);
        vector<bool> v(wordList.size() + 5, false);
        for (int i = 0; i < wordList.size(); ++i)
            for (int j = i + 1; j < wordList.size(); ++j)
            {
                if (valid(wordList[i], wordList[j]))
                {
                    m[i].insert(j);
                    m[j].insert(i);
                }
            }
        queue<int> q;
        v[0] = true;
        dis[0] = 0;
        q.push(0);
        while (!q.empty())
        {
            int p = q.front();
            q.pop();
            for (auto i : m[p])
            {
                if (!v[i])
                {
                    q.push(i);
                    v[i] = true;
                    dis[i] = dis[p] + 1;
                    if (wordList[i] == endWord)
                        dist = dis[i];
                }
            }
        }
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
