//
// Created by ByteDance on 2022/11/15.
//

#ifndef HOT100_24_H
#define HOT100_24_H


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *phead=new ListNode(-1,head),*pre=phead,*p,*q;
        while (pre->next&&pre->next->next){
            p=pre->next;
            q=p->next;
            pre->next=q;
            ListNode *temp=q->next;
            q->next=p;
            pre=p;
            p->next=temp;
        }
        return phead->next;
    }
};

#endif //HOT100_24_H
