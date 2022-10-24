//
// Created by 17336 on 2022/3/28.
//

#ifndef HOT100_143_H
#define HOT100_143_H

#include <linknode.h>

class Solution {
public:
    void reorderList(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *t = slow->next;
        slow->next = nullptr;
        slow = t;
        ListNode *pre = nullptr;
        while (slow) {
            ListNode *temp = slow->next;
            slow->next = pre;
            pre = slow;
            slow = temp;
        }
        ListNode *p = head;
        while (p&&pre) {
            ListNode *temp=pre->next;
            pre->next = p->next;
            p->next = pre;
            p = pre->next;
            pre = temp;
        }
    }
};

#endif //HOT100_143_H
