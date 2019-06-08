/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

/*
same as problem116
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root || !root->left && !root->right)
            return root;
        if (root->left)
            root->left->next = root->right;
        Node *cur = nullptr;
        if (root->right)
            cur = root->right;
        else
            cur = root->left;
        Node *r_cur = root->next;
        while (r_cur)
        {
            if (r_cur->left || r_cur->right)
            {
                if (r_cur->left)
                    cur->next = r_cur->left;
                else
                    cur->next = r_cur->right;
                break;
            }
            r_cur = r_cur->next;
        }
        connect(root->right);
        connect(root->left);
        return root;
    }
};
