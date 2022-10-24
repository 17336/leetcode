//
// Created by 17336 on 2022/4/7.
//

#ifndef HOT100_226_H
#define HOT100_226_H

#include "treenode.h"

using namespace std;

class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        if(root== nullptr) return root;
        TreeNode *temp=root->left;
        root->left= invertTree(root->right);
        root->right= invertTree(temp);
        return root;
    }
};

#endif //HOT100_226_H
