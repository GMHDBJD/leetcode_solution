/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 */

/*
two pointer
*/

#include <bits/stdc++.h>
using namespace std;

/*struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
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
            bool f = true;
            while (c->next && c->next->val == c->val)
            {
                c = c->next;
                f = false;
            }
            if (f)
                l = l->next = c;
            c = c->next;
        }
        l->next = nullptr;
        return new_list.next;
    }
};
