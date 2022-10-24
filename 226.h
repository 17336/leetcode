//
// Created by 17336 on 2021/11/4.
//

#ifndef HOT100_226_H
#define HOT100_226_H

#endif //HOT100_226_H

#include "algorithm"
#include "useful/treenode.h"
using namespace std;

class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        //递归出口
        if(root== nullptr) return root;
        //交换左右孩子指针
        swap(root->left,root->right);
        //翻转左子树
        invertTree(root->left);
        //翻转右子树
        invertTree(root->right);
        return root;
    }
};