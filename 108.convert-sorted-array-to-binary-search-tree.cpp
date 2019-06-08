/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
easy
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return rec(nums, 0, nums.size() - 1);
    }
    TreeNode *rec(vector<int> &nums, int b, int e)
    {
        if (b > e)
            return nullptr;
        int m = b + (e - b) / 2;
        TreeNode *new_node = new TreeNode(nums[m]);
        new_node->left = rec(nums, b, m - 1);
        new_node->right = rec(nums, m + 1, e);
        return new_node;
    }
};
