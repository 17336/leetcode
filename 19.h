//
// Created by 17336 on 2021/12/6.
//

#ifndef HOT100_19_H
#define HOT100_19_H

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *slow=head,*fast=head;
        while (n--) fast=fast->next;
        while (fast!= nullptr&& fast->next!= nullptr){
            fast=fast->next;
            slow=slow->next;
        }
        if(fast== nullptr) return head->next;
        slow->next=slow->next->next;
        return head;
    }
};

#endif //HOT100_19_H
