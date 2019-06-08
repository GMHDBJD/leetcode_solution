/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

#include <bits/stdc++.h>
using namespace std;

/*
    edge check
*/

class Solution
{
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
        {
            std::swap(nums1, nums2);
        }
        int l = 0, h = nums1.size() + 1;
        while (h - l >= 1)
        {
            int m = l + (h - l) / 2;
            int i = m;
            int j = (nums1.size() + nums2.size() + 1) / 2 - i;
            if (i > 0 && nums1[i - 1] > nums2[j])
            {
                h = m;
                continue;
            }
            if (i < nums1.size() && nums2[j - 1] > nums1[i])
            {
                l = m + 1;
                continue;
            }
            int lhs = 0;
            int rhs = 0;
            if (i == 0)
                lhs = nums2[j - 1];
            else if (j == 0)
                lhs = nums1[i - 1];
            else
                lhs = max(nums2[j - 1], nums1[i - 1]);
            if ((nums1.size() + nums2.size()) % 2 != 0)
                return lhs;
            if (i == nums1.size())
                rhs = nums2[j];
            else if (j == nums2.size())
                rhs = nums1[i];
            else
                rhs = min(nums2[j], nums1[i]);
            return lhs + double(rhs - lhs) / 2;
        }
        return 0;
    }
};
