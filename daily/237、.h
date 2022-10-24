//
// Created by 17336 on 2021/11/2.
//

#ifndef HOT100_237_H
#define HOT100_237_H

#endif //HOT100_237_H


/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode *node) {
        node->val=node->next->val;
        node->next=node->next->next;
    }
};