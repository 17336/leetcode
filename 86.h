//
// Created by 17336 on 2022/5/10.
//

#ifndef HOT100_86_H
#define HOT100_86_H

#include "linknode.h"

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *less = new ListNode(-1), *large = new ListNode(-1),*p=less,*q=large;
        while (head){
            if(head->val<x) {
                p->next=head;
                p=p->next;
            }
            else {
                q->next=head;
                q=q->next;
            }
            head=head->next;
        }
        p->next=large->next;
        q->next= nullptr;
        return less->next;
    }
};

#endif //HOT100_86_H
