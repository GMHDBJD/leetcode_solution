/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int sum)
    {
        return rec(root, 0, sum);
    }
    bool rec(TreeNode *root, int k, int sum)
    {
        if (root && !root->left && !root->right && sum == k + root->val)
            return true;
        if (!root)
            return false;
        return rec(root->left, k + root->val, sum) || rec(root->right, k + root->val, sum);
    }
};
