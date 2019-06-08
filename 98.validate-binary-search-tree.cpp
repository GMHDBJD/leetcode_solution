/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
inorder search
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        long m = LONG_MIN;
        return valid(root, m);
    }
    bool valid(TreeNode *root, long &min)
    {
        if (!root)
            return true;
        if (!valid(root->left, min))
            return false;
        if (root->val <= min)
            return false;
        min = root->val;
        if (!valid(root->right, min))
            return false;
        return true;
    }
};
