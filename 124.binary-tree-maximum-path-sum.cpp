/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
rec
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long result = INT_MIN;
    int maxPathSum(TreeNode *root)
    {
        auto p = res(root);
        return max(p.first, p.second);
    }
    pair<long, long> res(TreeNode *root)
    {
        if (!root)
            return {INT_MIN, INT_MIN};
        pair<long, long> l = res(root->left);
        pair<long, long> r = res(root->right);
        long one = max({l.first, r.first, 0l}) + root->val;
        long ll = max(l.first, 0l);
        long rr = max(r.first, 0l);
        long two = max({l.second, r.second, ll + rr + root->val});
        return {one, two};
    }
};
