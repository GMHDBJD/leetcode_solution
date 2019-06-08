/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
easy
*/

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (!head)
            return;
        ListNode *l = head;
        ListNode *r = head;
        while (r->next && r->next->next)
        {
            l = l->next;
            r = r->next->next;
        }
        r = reverse(l->next);
        l->next = nullptr;
        l = head;
        while (l && r)
        {
            ListNode *l_next = l->next;
            ListNode *r_next = r->next;
            l->next = r;
            r->next = l_next;
            l = l_next;
            r = r_next;
        }
    }
    ListNode *reverse(ListNode *head)
    {
        ListNode *pre = nullptr, *cur = head;
        while (cur)
        {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
