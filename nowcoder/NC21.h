//
// Created by 17336 on 2022/3/25.
//

#ifndef HOT100_NC21_H
#define HOT100_NC21_H

#include <linknode.h>

using namespace std;

class Solution {
public:
    /**
     *
     * @param head ListNode类
     * @param m int整型
     * @param n int整型
     * @return ListNode类
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write code here
        if (head->next == nullptr) return head;
        ListNode *p = head, *t = nullptr;
        int count = 1;
        while (count < m) {
            t = p;
            p = p->next;
            ++count;
        }
        ListNode *x = p;
        ListNode *pre = nullptr;
        while (count <= n) {
            ListNode *temp = p->next;
            p->next = pre;
            pre = p;
            p = temp;
            ++count;
        }
        if (t)
            t->next = pre;
        x->next = p;
        if (t != nullptr)
            return head;
        return pre;
    }
};

#endif //HOT100_NC21_H
