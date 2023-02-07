//
// Created by ByteDance on 2022/11/4.
//

#ifndef HOT100_83_H
#define HOT100_83_H

//leetcode submit region begin(Prohibit modification and deletion)

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode *p=head->next,*pre=head;
        while (p){
            if(p->val==pre->val) {
                pre->next=p->next;
                ListNode *temp=p;
                p=p->next;
                delete temp;
            }
            else{
                pre=pre->next;
                p=p->next;
            }
        }
        return head;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_83_H
