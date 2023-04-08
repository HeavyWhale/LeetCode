#include "../utils.h"

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        return optimal(root);
    }

private:
    Node* naive(Node* root) {
        if (root == nullptr) return nullptr;

        queue<pair<Node*, int>> q;
        q.emplace(root, 0);
        pair<Node*, int> prev {nullptr, -1};
        while (!q.empty()) {
            pair<Node*, int> cur = q.front(); q.pop();
            if (cur.first->left != nullptr) {
                q.emplace(cur.first->left, cur.second + 1);
                q.emplace(cur.first->right, cur.second + 1);
            }
            if (cur.second == prev.second) prev.first->next = cur.first;
            prev = cur;
        }
        return root;
    }

    Node* optimal(Node* root) {
        if (root == nullptr) return nullptr;

        for (Node* leftmost = root; leftmost->left != nullptr; leftmost = leftmost->left) {
            for (Node* cur = leftmost; cur != nullptr; cur = cur->next) {
                cur->left->next = cur->right;
                if (cur->next != nullptr) cur->right->next = cur->next->left;
            }
        }

        return root;
    }
};
