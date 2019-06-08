/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
last_visit
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> v;
        stack<TreeNode *> s;
        TreeNode *c = root;
        TreeNode *last_visit = nullptr;
        while (c || !s.empty())
        {
            if (c)
            {
                s.push(c);
                c = c->left;
            }
            else
            {
                c = s.top();
                if (!c->right || c->right == last_visit)
                {
                    s.pop();
                    v.push_back(c->val);
                    last_visit = c;
                    c = nullptr;
                }
                else
                {
                    c = c->right;
                }
            }
        }
        return v;
    }
};
