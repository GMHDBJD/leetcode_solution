/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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
find and swap
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
    void recoverTree(TreeNode *root)
    {
        TreeNode *pre = nullptr, *second = nullptr, *first = nullptr;
        inord(root, pre, first, second);
        if (first && second)
            swap(first->val, second->val);
    }
    void inord(TreeNode *t, TreeNode *&pre, TreeNode *&first, TreeNode *&second)
    {
        if (!t)
            return;
        inord(t->left, pre, first, second);
        if (pre && pre->val > t->val)
        {
            if (!first)
                first = pre;
            second = t;
        }
        pre = t;
        inord(t->right, pre, first, second);
    }
};
