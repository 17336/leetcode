//
// Created by 17336 on 2022/2/22.
//

#ifndef HOT100_21_H
#define HOT100_21_H

#include "linknode.h"

using namespace std;

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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        ListNode *res, *p;
        if (list1->val < list2->val) {
            res = list1;
            list1 = list1->next;
        } else {
            res = list2;
            list2 = list2->next;
        }
        p = res;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                p->next = list1;
                list1 = list1->next;
            } else {
                p->next = list2;
                list2 = list2->next;
            }
            p = p->next;
        }
        if (list1 == nullptr) p->next = list2;
        else p->next = list1;
        return res;
    }
};

#endif //HOT100_21_H
