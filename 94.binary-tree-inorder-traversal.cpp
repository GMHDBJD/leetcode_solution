/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 */
/**
 * Definition for a binary tree node.
 */

/*
stack, left , pop, right
*/

#include <bits/stdc++.h>
using namespace std;

/*
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};
        stack<TreeNode *> st;
        vector<int> v;
        bool flag = false;
        TreeNode *cur = root;
        while (!st.empty() || cur)
        {
            if (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = st.top();
                st.pop();
                v.push_back(cur->val);
                cur = cur->right;
            }
        }
        return v;
    }
};
