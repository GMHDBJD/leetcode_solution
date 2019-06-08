/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
many solution
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> r;
        for (int i = 0; true; ++i)
        {
            vector<int> v;
            if (!level(root, i, v))
                break;
            if (i % 2 != 0)
                reverse(v.begin(), v.end());
            r.push_back(v);
        }
        return r;
    }
    bool level(TreeNode *root, int l, vector<int> &v)
    {
        if (!root)
            return false;
        if (l == 0)
        {
            v.push_back(root->val);
            return true;
        }
        return level(root->left, l - 1, v) + level(root->right, l - 1, v);
    }
};
