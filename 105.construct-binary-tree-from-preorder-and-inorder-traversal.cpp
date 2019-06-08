/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
left and right by preorder
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        map<int, int> m;
        for (int i = 0; i < inorder.size(); ++i)
        {
            m[inorder[i]] = i;
        }
        return rec(0, 0, inorder.size()-1, preorder, inorder, m);
    }
    TreeNode *rec(int p, int ib, int ie, vector<int> &pre, vector<int> &in, map<int, int> &m)
    {
        if (ib > ie || p == pre.size())
            return nullptr;
        if (m[pre[p]] < ib || m[pre[p]] > ie)
            return nullptr;
        TreeNode *new_node = new TreeNode(pre[p]);
        new_node->left = rec(p + 1, ib, m[pre[p]] - 1, pre, in, m);
        new_node->right = rec(p + m[pre[p]] - ib + 1, m[pre[p]] + 1, ie, pre, in, m);
        return new_node;
    }
};
