/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
mergesort
*/

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        return mergeSort(head);
    }
    ListNode *mergeSort(ListNode *head)
    {
        ListNode *l = head, *r = head;
        if (!head || !head->next)
            return head;
        while (r->next && r->next->next)
        {
            l = l->next;
            r = r->next->next;
        }
        r = l->next;
        l->next = nullptr;
        l = mergeSort(head);
        r = mergeSort(r);
        return merge(l, r);
    }
    ListNode *merge(ListNode *l, ListNode *r)
    {
        if (!l)
            return r;
        if (!r)
            return l;
        if (l->val < r->val)
        {
            l->next = merge(l->next, r);
            return l;
        }
        else
        {
            r->next = merge(l, r->next);
            return r;
        }
    }
};
