/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */
/**
 * Definition for singly-linked list.
 *
 *struct ListNode
 *{
 *    int val;
 *    ListNode *next;
 *    ListNode(int x) : val(x), next(nullptr) {}
 *};
*/

/*
priority_queue or merge_sort
*/

#include <bits/stdc++.h>
using namespace std;

struct Cmp
{
    bool operator()(const ListNode *l, const ListNode *r)
    {
        return l->val > r->val;
    }
};
class Solution
{
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, Cmp> pq;
        for (auto &&i : lists)
        {
            if (i)
                pq.push(i);
        }
        ListNode head{0};
        ListNode *tail = &head;
        while (!pq.empty())
        {
            auto f = pq.top();
            pq.pop();
            tail = tail->next = f;
            if (f->next)
                pq.push(f->next);
        }
        return head.next;
    }
};
