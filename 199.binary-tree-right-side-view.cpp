/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
right then left
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int max = -1;
    vector<int> v;
    vector<int> rightSideView(TreeNode *root)
    {
        rec(root, 0);
        return v;
    }
    void rec(TreeNode *root, int l)
    {
        if (!root)
            return;
        if (l > max)
        {
            v.push_back(root->val);
            max=l;
        }
        rec(root->right,l+1);
        rec(root->left,l+1);
    }
};
