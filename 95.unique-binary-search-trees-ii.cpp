/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
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
same as problem86 but add inc
*/

#include <bits/stdc++.h>
using namespace std;

/*
*struct TreeNode
*{
*    int val;
*    TreeNode *left;
*    TreeNode *right;
*    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
*};
*/

class Solution
{
public:
    vector<TreeNode *> generateTrees(int n)
    {

        vector<vector<TreeNode *>> dp(n + 5, vector<TreeNode *>());
        dp[0].push_back(nullptr);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                for (auto &l : dp[j - 1])
                {
                    for (auto &r : dp[i - j])
                    {
                        TreeNode *new_node = new TreeNode(j);
                        new_node->left = inc(l, 0);
                        new_node->right = inc(r, j);
                        dp[i].push_back(new_node);
                    }
                }
            }
        }
        if (n == 0)
            return {};
        return dp[n];
    }
    TreeNode *inc(const TreeNode *treenode, int k)
    {
        if (treenode)
        {
            TreeNode *new_node = new TreeNode(treenode->val + k);
            new_node->left = inc(treenode->left, k);
            new_node->right = inc(treenode->right, k);
            return new_node;
        }
        else
            return nullptr;
    }
};
