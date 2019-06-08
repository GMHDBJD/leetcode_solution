/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

/*
dfs,bfs
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<Node *, Node *> s;
    Node *cloneGraph(Node *node)
    {
        if (s.count(node))
            return s[node];
        Node *new_node = new Node(-1, {});
        s[node] = new_node;
        vector<Node *> v;
        for (auto &&i : node->neighbors)
            v.push_back(cloneGraph(i));
        new_node->val = node->val;
        new_node->neighbors = v;
        s[node] = new_node;
        return new_node;
    }
};
