/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
same as problem 82
*/

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode new_list(-1);
        ListNode *c = head;
        ListNode *l = &new_list;
        while (c)
        {
            while (c->next && c->next->val == c->val)
                c = c->next;
            l = l->next = c;
            c = c->next;
        }
        l->next = nullptr;
        return new_list.next;
    }
};
