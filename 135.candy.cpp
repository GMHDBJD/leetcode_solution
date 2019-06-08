/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

/*
greedy
amazing with 121
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        if (ratings.size() <= 1)
            return ratings.size();
        vector<int> r(ratings.size() + 5, 1);
        vector<pair<int, int>> v(ratings.size() + 5);
        for (int i = 0; i < ratings.size(); ++i)
            v[i] = {ratings[i], i};
        sort(v.begin(), v.begin() + ratings.size());
        for (int i = 0; i < ratings.size(); ++i)
        {
            auto p = v[i];
            int pos = p.second;
            int ra = p.first;
            if (pos == 0 && ratings[pos + 1] < ratings[pos])
                r[pos] = max(r[pos + 1] + 1, r[pos]);
            else if (pos == ratings.size() - 1 && ratings[pos - 1] < ratings[pos])
                r[pos] = max(r[pos - 1] + 1, r[pos]);
            else if (pos > 0 && pos < ratings.size() - 1 && (ratings[pos + 1] < ratings[pos] || ratings[pos - 1] < ratings[pos]))
            {
                if (ratings[pos + 1] < ratings[pos])
                    r[pos] = max(r[pos + 1] + 1, r[pos]);
                if (ratings[pos - 1] < ratings[pos])
                    r[pos] = max(r[pos - 1] + 1, r[pos]);
            }
        }
        int sum = 0;
        for (int i = 0; i < ratings.size(); ++i)
            sum += r[i];
        return sum;
    }
};
