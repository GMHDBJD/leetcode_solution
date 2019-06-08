/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
same as problem105
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        map<int, int> m;
        for (int i = 0; i < inorder.size(); ++i)
            m[inorder[i]] = i;
        return rec(postorder.size() - 1, 0, postorder.size() - 1, inorder, postorder, m);
    }
    TreeNode *rec(int p, int b, int e, vector<int> &inorder, vector<int> &postorder, map<int, int> &m)
    {
        if (p < 0 || b > e)
            return nullptr;
        if (m[postorder[p]] < b || m[postorder[p]] > e)
            return nullptr;
        int mi = m[postorder[p]];
        TreeNode *new_node = new TreeNode(postorder[p]);
        new_node->right = rec(p - 1, mi + 1, e, inorder, postorder, m);
        new_node->left = rec(p - (e - mi) - 1, b, mi - 1, inorder, postorder, m);
        return new_node;
    }
};
