/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 */

#include <bits/stdc++.h>
using namespace std;

/*
*struct ListNode
*{
*    int val;
*    ListNode *next;
*    ListNode(int x) : val(x), next(NULL) {}
*};
*/

/*
better new_list
*/

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode **ll = &head;
        ListNode **rl = &head;
        while (*rl)
        {
            if (ll == rl && (*ll)->val < x)
            {
                ll = &(*ll)->next;
                rl = &(*rl)->next;
            }
            else if (ll != rl && (*rl)->val < x)
            {
                ListNode *r = (*rl);
                (*rl) = r->next;
                r->next = *ll;
                *ll = r;
                ll = &(*ll)->next;
            }
            else
                rl = &(*rl)->next;
        }
        return head;
    }
};
