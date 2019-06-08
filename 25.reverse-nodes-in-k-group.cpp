/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 */
/**
  Definition for singly-linked list.
 
 *struct ListNode
 *{
 *    int val;
 *    ListNode *next;
 *    ListNode(int x) : val(x), next(nullptr) {}
 *};
*/

/*
recursive
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *cur = head;
        int t = k;
        while (t--)
        {
            if (!cur)
                return head;
            cur = cur->next;
        }
        ListNode *pre = reverseKGroup(cur, k);
        cur = head;
        while (k--)
        {
            ListNode *temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};
