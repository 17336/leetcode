//
// Created by 17336 on 2021/11/22.
//

#ifndef HOT100_LINKNODE_H
#define HOT100_LINKNODE_H


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#endif //HOT100_LINKNODE_H
