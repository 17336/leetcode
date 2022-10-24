//
// Created by 17336 on 2022/3/4.
//

#ifndef HOT100_148_H
#define HOT100_148_H

#include "linknode.h"
#include <algorithm>

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
        if (head == nullptr || head->next == nullptr) return head;
        //对于单链表排序，冒牌排序比较适合
        ListNode *p, *end = nullptr;
        bool flag = true;
        //单链表不能随机访问，所以用end记录已经有序的后半段的起点
        while (head->next != end) {
            p = head;
            //每次冒泡到end就结束，如果本次冒泡一个也没交换，说明已经有序
            while (p->next != end) {
                if (p->val > p->next->val) {
                    std::swap(p->val, p->next->val);
                    flag = false;
                }
                p = p->next;
            }
            if (flag) return head;
            end = p;
        }
        return head;
    }
};

#endif //HOT100_148_H
