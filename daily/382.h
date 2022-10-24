//
// Created by 17336 on 2022/1/16.
//

#ifndef HOT100_382_H
#define HOT100_382_H


#include "stdlib.h"

using namespace std;
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
    ListNode *head;
public:
    Solution(ListNode* head) {
        this->head=head;
    }

    int getRandom() {
        ListNode *p=head;
        int res,i=0;
        while (p!= nullptr){
            if(rand()%++i==0) res=p->val;
            p=p->next;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

#endif //HOT100_382_H
