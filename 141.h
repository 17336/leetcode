//
// Created by 17336 on 2022/3/3.
//

#ifndef HOT100_141_H
#define HOT100_141_H

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
    bool hasCycle(ListNode *head) {
        if(head== nullptr) return false;
        ListNode *fast=head,*slow=head;
        while (fast!= nullptr&&fast->next!= nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow) return true;
        }
        return false;
    }
};

#endif //HOT100_141_H
