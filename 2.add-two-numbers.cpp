/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    carry in condition
    first in while
    separate if
*/

class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *sol = new ListNode(0);
        ListNode *temp = sol;
        int sum = 0;
        int c = 0;
        while (l1 || l2 || c)
        {
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            if (c)
            {
                sum += c;
            }
            c = sum / 10;
            sol->next = new ListNode(sum % 10);
            sum = 0;
            sol = sol->next;
        }
        return temp->next;
    }
};
