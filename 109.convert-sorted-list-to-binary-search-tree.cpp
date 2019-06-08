/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
same as problem108
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        vector<int> v;
        for (auto i = head; i != nullptr; i = i->next)
        {
            v.push_back(i->val);
        }
        return rec(v, 0, v.size() - 1);
    }
    TreeNode *rec(vector<int> &nums, int b, int e)
    {
        if (b > e)
            return nullptr;
        int m = b + (e - b) / 2;
        TreeNode *new_node = new TreeNode(nums[m]);
        new_node->left = rec(nums, b, m - 1);
        new_node->right = rec(nums, m + 1, e);
        return new_node;
    }
};
