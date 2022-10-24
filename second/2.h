//
// Created by 17336 on 2022/3/25.
//

#ifndef HOT100_2_H
#define HOT100_2_H

#include <linknode.h>

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *res = new ListNode(-1), *p = res;
        int c = 0;
        while (l1 != nullptr && l2 != nullptr) {
            p->next = new ListNode((l1->val + l2->val + c) % 10);
            c = (l1->val + l2->val+c) / 10;
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l2 != nullptr) l1 = l2;
        while (c!=0&&l1 != nullptr) {
            p->next = new ListNode((l1->val + c) % 10);
            c = (l1->val +c) / 10;
            l1 = l1->next;
            p = p->next;
        }
        if(c!=0) p->next=new ListNode(c);
        if(l1!= nullptr) p->next=l1;
        return res->next;
    }
};

#endif //HOT100_2_H
