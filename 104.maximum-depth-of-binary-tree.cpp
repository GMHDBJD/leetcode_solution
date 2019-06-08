/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        return rec(root, 0);
    }
    int rec(TreeNode *root, int k)
    {
        if (!root)
            return k;
        else
            return max(rec(root->left, k + 1), rec(root->right, k + 1));
    }
};
