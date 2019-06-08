/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/

/*
backtracking
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<Node *, Node *> m;
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return head;
        if (m.count(head))
            return m[head];
        Node *node = new Node();
        m[head] = node;
        node->val = head->val;
        node->next = copyRandomList(head->next);
        node->random = copyRandomList(head->random);
        m[head] = node;
        return node;
    }
};
