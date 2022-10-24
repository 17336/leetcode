//
// Created by 17336 on 2022/2/23.
//

#ifndef HOT100_23_H
#define HOT100_23_H

#include "linknode.h"
#include "queue"
#include "algorithm"
#include "functional"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

bool func(ListNode *p, ListNode *q) {
    return p->val > q->val;
}

struct myGreater {
    bool operator()(ListNode *p, ListNode *q) {
        return p->val > q->val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        //function<bool(ListNode *, ListNode *)> f([](ListNode *p, ListNode *q) -> bool { return p->val > q->val; });
        //function<bool(ListNode *, ListNode *)> f(func);
        priority_queue<ListNode *, vector<ListNode *>, myGreater> queue;
        for (const auto &item: lists) {
            if (item != nullptr)queue.push(item);
        }
        ListNode *res = new ListNode(0XFFFFFFFF), *p = res;
        while (!queue.empty()) {
            ListNode *temp = queue.top();
            p->next = temp;
            p = temp;
            queue.pop();
            if (temp->next != nullptr) queue.push(temp->next);
        }
        p->next = nullptr;
        return res->next;
    }
};

#endif //HOT100_23_H
