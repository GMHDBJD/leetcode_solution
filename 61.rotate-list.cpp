/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 */

/*
better circle the list
*/

#include <bits/stdc++.h>
using namespace std;

/*
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
*/

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next)
            return head;
        int s = 0;
        ListNode *t = head;
        while (t)
        {
            ++s;
            t = t->next;
        }
        k %= t;
        ListNode *l = head;
        ListNode *r = head;
        while (k--)
            r = r->next;
        while (r->next)
        {
            l = l->next;
            r = r->next;
        }
        r->next = head;
        ListNode *temp = l->next;
        l->next = nullptr;
        return temp;
    }
};
