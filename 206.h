//
// Created by 17336 on 2022/3/7.
//

#ifndef HOT100_206_H
#define HOT100_206_H

#include "linknode.h"

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
class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *p = head, *q = head->next;
        p->next = nullptr;
        while (q){
            ListNode *temp = q->next;
            q->next = p;
            p = q;
            q = temp;
        }
        return p;
    }
};

#endif //HOT100_206_H
