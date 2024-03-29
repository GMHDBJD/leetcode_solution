/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
niubility
*/

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *l = headA;
        ListNode *r = headB;
        while (l != r)
        {
            l = l == nullptr ? headB : l->next;
            r = r == nullptr ? headA : r->next;
        }
        return l;
    }
};
