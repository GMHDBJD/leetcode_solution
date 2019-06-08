/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
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
new_list
*/

class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode new_node(0);
        ListNode *c = head;
        ListNode *pre = &new_node;
        ListNode *next = nullptr;
        while (c)
        {
            next = c->next;
            while (pre->next && pre->next->val < c->val)
                pre = pre->next;
            c->next = pre->next;
            pre->next = c;
            c = next;
            pre = &new_node;
        }
        return new_node.next;
    }
};
