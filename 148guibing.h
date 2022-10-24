//
// Created by 17336 on 2022/3/4.
//

#ifndef HOT100_148GUIBING_H
#define HOT100_148GUIBING_H

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
    ListNode *sortList(ListNode *head) {
        if (head == nullptr||head->next== nullptr) return head;
        ListNode *fast = head, *slow = head;
        //找中点
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        return merge(sortList(head), sortList(fast));
    }

    ListNode *merge(ListNode *a, ListNode *b) {
        if (a == nullptr) return b;
        if (b == nullptr) return a;
        ListNode *res = new ListNode(), *end = res;
        while (a && b) {
            if (a->val < b->val) {
                end->next = a;
                end = a;
                a = a->next;
            } else {
                end->next = b;
                end = b;
                b = b->next;
            }
        }
        if (a == nullptr) end->next = b;
        else end->next = a;
        return res->next;
    }
};

#endif //HOT100_148GUIBING_H
