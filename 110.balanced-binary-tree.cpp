/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    bool isBalanced(TreeNode *root)
    {
        return rec(root) != -1;
    }
    int rec(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = rec(root->left);
        int r = rec(root->right);
        if (l == -1 || r == -1 || abs(l - r) > 1)
            return -1;
        return max(l, r) + 1;
    }
};
