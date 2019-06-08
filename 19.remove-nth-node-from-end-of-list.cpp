/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */
/**
 * Definition for singly-linked list.
 *
 *struct ListNode
 *{
 *    int val;
 *    ListNode *next;
 *    ListNode(int x) : val(x), next(nullptr) {}
 *};
 */

/*
so easy
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode **link_ptr = &head;
        ListNode *r = head;
        while (--n)
            r = r->next;
        while (r->next)
        {
            r = r->next;
            link_ptr = &((*link_ptr)->next);
        }
        ListNode *delete_node = *link_ptr;
        *link_ptr = delete_node->next;
        delete delete_node;
        return head;
    }
};
