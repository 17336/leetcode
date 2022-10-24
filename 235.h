//
// Created by 17336 on 2022/4/3.
//

#ifndef HOT100_235_H
#define HOT100_235_H

#include "treenode.h"

class Solution {
    TreeNode *res = nullptr;
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        contain(root,p,q);
        return res;
    }

    bool contain(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr) return false;
        bool isLeft = contain(root->left,p,q), isRight = contain(root->right,p,q);
        if((isLeft&&isRight)||((root->val==p->val||root->val==q->val)&&(isLeft||isRight))) {
            res=root;
            return true;
        }
        return isLeft||isRight||(root->val==p->val||root->val==q->val);
    }
};

#endif //HOT100_235_H
