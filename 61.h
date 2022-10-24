//
// Created by 17336 on 2022/4/2.
//

#ifndef HOT100_61_H
#define HOT100_61_H

#include "linknode.h"

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(head== nullptr) return head;
        //计算链表长度
        int len = 0;
        ListNode *p = head;
        while (p) {
            ++len;
            p = p->next;
        }
        k = k % len;
        if (k == 0) return head;
        int i = 0;
        //找到倒数第k个链表结点
        ListNode *fast = head, *slow = head;
        while (i < k ) {
            fast = fast->next;
            ++i;
        }
        while (fast->next){
            fast=fast->next;
            slow=slow->next;
        }

        fast->next=head;
        head=slow->next;
        slow->next= nullptr;
        return head;
    }
};

#endif //HOT100_61_H
