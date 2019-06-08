/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
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
    bool hasCycle(ListNode *head)
    {
        if (!head)
            return false;
        ListNode *l = head;
        ListNode *r = head;
        while (r->next && r->next->next)
        {
            l = l->next;
            r = r->next->next;
            if (l == r)
                return true;
        }
        return false;
    }
};
