/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

/*
better store in back
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int l = m - 1;
        int r = n + m - 1;
        while (l >= 0)
            nums1[r--] = nums1[l--];
        l = n;
        r = 0;
        int c = 0;
        while (r != n || l != m + n)
        {
            if (r != n && l != m + n)
                nums1[c++] = nums1[l] < nums2[r] ? nums1[l++] : nums2[r++];
            else if (r != n)
                nums1[c++] = nums2[r++];
            else
                nums1[c++] = nums1[l++];
        }
        return;
    }
};
