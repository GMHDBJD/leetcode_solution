/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<int> v;
        vector<vector<int>> r;
        rec(root, 0, sum, v, r);
        return r;
    }
    void rec(TreeNode *root, int k, int sum, vector<int> &v, vector<vector<int>> &r)
    {
        if (!root)
            return;
        if (!root->left && !root->right && sum == k + root->val)
        {
            v.push_back(root->val);
            r.push_back(v);
            v.pop_back();
            return;
        }
        v.push_back(root->val);
        rec(root->left, k + root->val, sum, v, r);
        rec(root->right, k + root->val, sum, v, r);
        v.pop_back();
    }
};
