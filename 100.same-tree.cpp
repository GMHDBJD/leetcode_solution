/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
 */
/**
 * Definition for a binary tree node.
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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p && !q || !p && q)
            return false;
        if (!p && !q)
            return true;
        if (p->val != q->val)
            return false;
        bool a = isSameTree(p->left, q->left);
        bool b = isSameTree(p->right, q->right);
        return a && b;
    }
};
