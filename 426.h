//
// Created by 17336 on 2022/3/21.
//

#ifndef HOT100_426_H
#define HOT100_426_H

#include <vector>

class Node {
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {

public:
    Node *treeToDoublyList(Node *root) {
        if(root== nullptr) return nullptr;
        std::pair<Node *, Node *> t = rec(root);
        t.first->left = t.second;
        t.second->right = t.first;
        return t.first;
    }

    std::pair<Node *, Node *> rec(Node *root) {
        if (root == nullptr) return {nullptr, nullptr};
        std::pair<Node *, Node *> l = rec(root->left), r = rec(root->right);
        Node *head, *tail;
        if (l.second) {
            l.second->right = root;
            head = l.first;
        } else head=root;
        root->left = l.second;
        if (r.first) {
            r.first->left = root;
            tail=r.second;
        } else tail=root;
        root->right = r.first;
        return {head, tail};
    }
};

#endif //HOT100_426_H
