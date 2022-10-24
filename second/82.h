//
// Created by 17336 on 2022/3/28.
//

#ifndef HOT100_82_H
#define HOT100_82_H

#include "linknode.h"

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *dum = new ListNode(1001, head), *p = dum;
        while (p->next) {
            int x = p->next->val;
            //如果p后面两个是重复值，则一直删除所有重复值x
            if (p->next->next && x == p->next->next->val) {
                ListNode *q = p->next;
                while (q && q->val == x) {
                    ListNode *temp=q;
                    p->next = q->next;
                    q = q->next;
                    delete temp;
                }
            } else p = p->next;
        }
        return dum->next;
    }
};

#endif //HOT100_82_H
