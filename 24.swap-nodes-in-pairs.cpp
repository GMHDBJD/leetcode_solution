/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
same as reverse
*/

class Solution
{
  public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode **link_ptr = &head;
        while (*link_ptr)
        {
            ListNode *current = *link_ptr;
            ListNode *next = current->next;
            if (next)
            {
                current->next = next->next;
                next->next = current;
                *link_ptr = next;
                link_ptr = &((*link_ptr)->next);
            }
            link_ptr = &((*link_ptr)->next);
        }
        return head;
    }
};
