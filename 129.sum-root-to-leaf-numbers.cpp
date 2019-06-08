/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
dfs
*/

class Solution
{
public:
    int m = 0;
    int sumNumbers(TreeNode *root)
    {
        if (!root)
            return 0;
        rec(root, 0);
        return m;
    }
    void rec(TreeNode *root, long s)
    {
        long sum = s * 10 + root->val;
        if (!root->left && !root->right)
        {
            m += sum;
            return;
        }
        if (root->left)
            rec(root->left, sum);
        if (root->right)
            rec(root->right, sum);
    }
};
