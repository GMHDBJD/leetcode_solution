/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 */

/*
k and use fraction
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int ma = 0;
        if (points.size() < 2)
            return points.size();
        for (int i = 0; i < points.size(); ++i)
        {
            map<pair<int, int>, int> m;
            int s = 0, v = 0, lma = 0;
            for (int j = i + 1; j < points.size(); ++j)
            {
                if (points[i] == points[j])
                {
                    ++s;
                }
                else if (points[i][0] == points[j][0])
                {
                    ++v;
                }
                else
                {
                    int x = points[i][0] - points[j][0];
                    int y = points[i][1] - points[j][1];
                    int gcd = GCD(x, y);
                    x = x / gcd;
                    y = y / gcd;
                    m[{x, y}]++;
                    lma = max(lma, m[{x, y}]);
                }
            }
            ma = max({ma, v + 1, lma + s + 1});
        }
        return ma;
    }
    int GCD(int x, int y)
    {
        if (y == 0)
            return x;
        else
            return GCD(y, x % y);
    }
};
