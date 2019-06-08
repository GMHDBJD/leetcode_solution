/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 */
/**
 * Definition for singly-linked list.
 */

/*
remember list next
*/

#include <bits/stdc++.h>
using namespace std;

/*
* struct ListNode
* {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        ListNode *pre = nullptr, *cur = head;
        while (--m)
        {
            pre = cur;
            cur = cur->next;
            --n;
        }
        ListNode *p = pre;
        ListNode *t = cur;
        while (n--)
        {
            ListNode *n = cur->next;
            cur->next = pre;
            pre = cur;
            cur = n;
        }
        t->next = cur;
        if (p)
            p->next = pre;
        else
            head = pre;
        return head;
    }
};
