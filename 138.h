//
// Created by 17336 on 2022/4/9.
//

#ifndef HOT100_138_H
#define HOT100_138_H

#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node *copyRandomList(Node *head) {
        unordered_map<Node *, Node *> srcToDest;
        Node *p = head;
        Node *res = new Node(-1), *q = res;
        while (p) {
            q->next = new Node(p->val);
            q = q->next;
            srcToDest[p]=q;
            p = p->next;
        }
        q=res->next;
        p=head;
        while (p){
            q->random=srcToDest[p->random];
            p=p->next;
            q=q->next;
        }
        return res->next;
    }
};

#endif //HOT100_138_H
