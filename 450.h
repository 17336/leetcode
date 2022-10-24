//
// Created by 17336 on 2022/6/2.
//

#ifndef HOT100_450_H
#define HOT100_450_H

#include <basi.h>

class Solution {
public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        TreeNode *quard = new TreeNode(INT_MAX, root, nullptr);
        TreeNode *p = root, *pre=quard;
        while (p != nullptr) {
            if (p->val == key) break;
            pre = p;
            if (p->val > key) p = p->left;
            else if (p->val < key) p = p->right;
        }
        //没查找到
        if (p == nullptr) return quard->left;
        if (p->right == nullptr) {
            if(pre->val<p->val) pre->right=p->left;
            else pre->left=p->left;
            return quard->left;
        }
        if(p->left== nullptr){
            if(pre->val<p->val) pre->right=p->right;
            else pre->left=p->right;
            return quard->left;
        }
        TreeNode *pp = p->right, *min;
        if (pp->left == nullptr) {
            pp->left = p->left;
            if(pre->val<p->val) pre->right=pp;
            else pre->left=pp;
            return quard->left;
        }
        min = pp->left;
        while (min->left) {
            pp = min;
            min = min->left;
        }
        pp->left = min->right;
        min->left = p->left;
        min->right = p->right;
        if(pre->val<p->val) pre->right=min;
        else pre->left=min;
        return quard->left;
    }
};

#endif //HOT100_450_H
