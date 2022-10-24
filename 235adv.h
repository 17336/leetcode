//
// Created by 17336 on 2022/4/3.
//

#ifndef HOT100_235ADV_H
#define HOT100_235ADV_H

#include "treenode.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val==p->val||root->val==q->val) return root;
        if((p->val>root->val)^(q->val>root->val)) return root;
        if(p->val>root->val) return lowestCommonAncestor(root->right,p,q);
        return lowestCommonAncestor(root->left,p,q);
    }
};

#endif //HOT100_235ADV_H
