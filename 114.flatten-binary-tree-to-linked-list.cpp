/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
amazing
right, left, current
*/

class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (!root)
            return;
        flatten(root->right);
        flatten(root->left);
        root->right = next;
        root->left = nullptr;
        next = root;
    }
    TreeNode *next = nullptr;
};
