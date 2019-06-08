/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> v;
        stack<TreeNode *> s;
        if (!root)
            return v;
        s.push(root);
        while (!s.empty())
        {
            TreeNode *c = s.top();
            s.pop();
            v.push_back(c->val);
            if (c->right)
                s.push(c->right);
            if (c->left)
                s.push(c->left);
        }
        return v;
    }
};
