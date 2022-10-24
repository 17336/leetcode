//
// Created by 17336 on 2022/3/24.
//

#ifndef HOT100_25_H
#define HOT100_25_H

#include <linknode.h>

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        //长度小于k的直接返回
        ListNode *p = head;
        int count = 0;
        while (count < k && p != nullptr) {
            ++count;
            p = p->next;
        }
        if (count < k) return head;

        //翻转head起始的k个结点
        ListNode *q = head, *pre = nullptr;
        while (q != p) {
            ListNode *temp=q->next;
            q->next=pre;
            pre=q;
            q=temp;
        }
        //递归翻转后面几组的链表，返回翻转后头节点并接在本次尾节点上
        head->next= reverseKGroup(q,k);
        return pre;
    }
};

#endif //HOT100_25_H
