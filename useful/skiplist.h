//
// Created by 17336 on 2022/3/24.
//

#ifndef HOT100_SKIPLIST_H
#define HOT100_SKIPLIST_H

#include <stack>
#include <stdlib.h>

using namespace std;

struct listNode {
    int val;
    listNode *next, *pre, *down, *up;

    listNode(int v) : val(v), next(nullptr), down(nullptr), pre(nullptr) {}
};

class Skiplist {
    listNode *head = new listNode(-1);
    int maxHeight = 32;
    int high = 1;
public:
    Skiplist() {
    }

    bool search(int target) {
        listNode *p = head;
        while (p != nullptr) {
            if (p->pre != nullptr && p->val == target) return true;
            if (p->next == nullptr || target < p->next->val) {
                p = p->down;
            } else p = p->next;
        }
        return false;
    }

    void add(int num) {
        listNode *p = head;
        std::stack<listNode *> path;
        while (p != nullptr) {
            if (p->pre != nullptr && p->val == num) return;
            if (p->next == nullptr || num < p->next->val) {
                path.push(p);
                p = p->down;
            } else p = p->next;
        }
        int ran;
        listNode *down = nullptr;
        do {
            p = path.top();
            path.pop();
            listNode *s = new listNode(num);
            s->next = p->next;
            s->pre = p;
            if (s->next)
                s->next->pre = s;
            p->next = s;
            s->down = down;
            down = s;
            ran = rand() % 2;
        } while (!path.empty() && ran);
        if (path.empty() && high < maxHeight && ran) {
            ++high;
            listNode *newHead = new listNode(-1);
            newHead->down = head;
            head = newHead;
            listNode *s = new listNode(num);
            head->next = s;
            s->pre = head;
            s->next = nullptr;
            s->down = down;
        }
    }

    bool erase(int num) {
        listNode *p = head;
        while (p != nullptr) {
            if (p->pre != nullptr && p->val == num) {
                while (p != nullptr) {
                    p->pre->next = p->next;
                    if (p->next) p->next->pre = p->pre;
                    listNode *temp = p;
                    p = p->down;
                    delete temp;
                }
                return true;
            }
            if (p->next == nullptr || num < p->next->val) {
                p = p->down;
            } else p = p->next;
        }
        return false;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */

#endif //HOT100_SKIPLIST_H
