//
// Created by 17336 on 2022/4/4.
//

#ifndef HOT100_98_H
#define HOT100_98_H

#include "treenode.h"
#include <limits.h>

using namespace std;

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isVBST(root,LONG_MAX,LONG_MIN);
    }

    bool isVBST(TreeNode *root,long up,long down){
        if(root== nullptr) return true;
        if(root->val<=down||root->val>=up) return false;
        return isVBST(root->left,root->val,down)&&isVBST(root->right,up,root->val);
    }
};

#endif //HOT100_98_H
