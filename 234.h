//
// Created by 17336 on 2021/11/22.
//

#ifndef HOT100_234_H
#define HOT100_234_H

#include "useful/linknode.h"

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        ListNode *fast = head, *slow=head;
        while (fast!= nullptr&&fast->next!= nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode *other;
        if(fast) other=reverse(slow->next);
        else other=reverse(slow);
        while (other!= nullptr){
            if(other->val!=head->val) return false;
            other=other->next;
            head=head->next;
        }
        return true;
    }
    ListNode *reverse(ListNode *p){
        ListNode *temp,*last = nullptr,*head=p;
        while (p){
            head=p;
            temp=p->next;
            p->next=last;
            last=p;
            p=temp;
        }
        return head;
    }
};

#endif //HOT100_234_H
