//
// Created by ByteDance on 2022/11/1.
//

#ifndef HOT100_22_H
#define HOT100_22_H

//leetcode submit region begin(Prohibit modification and deletion)

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *fast=head,*slow=head;
        for (int i = 0; i < k; ++i) {
            fast=fast->next;
        }
        while (fast!= nullptr){
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_22_H
