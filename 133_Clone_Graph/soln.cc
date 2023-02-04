#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(const Node* root) {
        if (root == NULL) return NULL;
        
        deque<const Node*> Q { root };
        unordered_map<const Node*, Node*> visited { {root, new Node(root->val)} };

        const Node* node;
        Node* nnode;
        while (!Q.empty()) {
            node = Q.at(0); Q.pop_front();
            for (const Node* neighbour : node->neighbors) {
                if (visited.count(neighbour) == 0) {
                    visited[neighbour] = new Node(neighbour->val);
                    Q.emplace_back(neighbour);
                }
                visited[node]->neighbors.emplace_back(visited[neighbour]);
            }
        }

        return visited[root];
    }
};
