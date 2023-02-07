//
// Created by ByteDance on 2022/11/15.
//

#ifndef HOT100_24RECURSION_H
#define HOT100_24RECURSION_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode *p=head->next,*q=p->next;
        p->next=head;
        head->next= swapPairs(q);
        return p;
    }
};

#endif //HOT100_24RECURSION_H
