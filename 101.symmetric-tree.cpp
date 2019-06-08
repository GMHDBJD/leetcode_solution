/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
left->left==right->right && left->right==right->left
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root)
            return valid(root->left, root->right);
        else
            return true;
    }
    bool valid(TreeNode *left, TreeNode *right)
    {
        if (!left && !right)
            return true;
        else if (left && right && left->val == right->val)
            return valid(left->left, right->right) && valid(left->right, right->left);
        else
            return false;
    }
};
