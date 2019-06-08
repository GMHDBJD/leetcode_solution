/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
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
two pointer
*/

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head)
            return nullptr;
        ListNode *l = head;
        ListNode *r = head;
        bool flag = false;
        while (r->next && r->next->next)
        {
            l = l->next;
            r = r->next->next;
            if (l == r)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
            return nullptr;
        l = head;
        while (l != r)
        {
            l = l->next;
            r = r->next;
        }
        return l;
    }
};
