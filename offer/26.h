//
// Created by 17336 on 2022/3/23.
//

#ifndef HOT100_26_H
#define HOT100_26_H

#include "treenode.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSubStructure(TreeNode *A, TreeNode *B) {
        if (B == nullptr) return false;
        if(func(A,B)) return true;
        if(A->left&& isSubStructure(A->left,B)) return true;
        if(A->right&& isSubStructure(A->right,B)) return true;
        return false;
    }

    //判断B是否是以A为根节点的子结构
    bool func(TreeNode *A, TreeNode *B) {
        //空树一定是
        if (B == nullptr) return true;
        //A空B不空，一定不是
        if (A == nullptr) return false;
        //值不相等一定不是
        if (A->val != B->val) return false;
        //值相等，递归左右子树(注意左右子树也分别对应根节点)
        return func(A->left, B->left) && func(A->right, B->right);
    }
};

#endif //HOT100_26_H
