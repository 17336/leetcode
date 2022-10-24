//
// Created by 17336 on 2021/11/21.
//

#ifndef HOT100_559_H
#define HOT100_559_H

#endif //HOT100_559_H

#include "algorithm"

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    int maxDepth(Node *root) {
        if (root)
            return func(root, 1);
        return 0;
    }

    int func(Node *root, int depth) {
        int maxdepth = depth;
        for (const auto &child: root->children) {
            maxdepth = max(maxdepth, func(child, depth + 1));
        }
        return maxdepth;
    }
};