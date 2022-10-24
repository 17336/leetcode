//
// Created by 17336 on 2022/3/4.
//

#ifndef HOT100_160_H
#define HOT100_160_H

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1=0,len2=0;
        ListNode *p1=headA,*p2=headB;
        while (p1){
            len1++;
            p1=p1->next;
        }
        while (p2){
            len2++;
            p2=p2->next;
        }
        int minus;
        if(len1>len2) {
            p1=headA;
            p2=headB;
            minus=len1-len2;
        } else{
            p1=headB;
            p2=headA;
            minus=len2-len1;
        }
        for (int i = 0; i < minus; ++i) {
            p1=p1->next;
        }
        while (p1!=p2){
            p1=p1->next;
            p2=p2->next;
        }
        return p1;
    }
};

#endif //HOT100_160_H
