//
// Created by 17336 on 2022/3/3.
//

#ifndef HOT100_142_H
#define HOT100_142_H

#include "linknode.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) {
                ListNode *p=head;
                while (p!=slow){
                    p=p->next;
                    slow=slow->next;
                }
                return p;
            }
        }
        return nullptr;
    }
};

#endif //HOT100_142_H
