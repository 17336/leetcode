//
// Created by 17336 on 2022/3/9.
//

#ifndef HOT100_236ADV_H
#define HOT100_236ADV_H

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
    TreeNode *res;
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        //该函数同时判断是否包含p、q和找LCA
        containPOrQ(root,p,q);
        return res;
    }

    //多返回值函数，判断以x为根的树是否包含p或q(返回bool)，同时利用x的左右子树bool判断是否是公共祖先(置成员变量res)
    bool containPOrQ(TreeNode *x, TreeNode *p, TreeNode *q) {
        if(x== nullptr) return false;
        bool lson=containPOrQ(x->left,p,q);
        //如果在左子树递归过程中找到了LCA，就不用在递归右子树了，立即返回
        if(res) return true;
        bool rson= containPOrQ(x->right,p,q);
        //如果在右子树递归过程中找到了LCA，立即返回
        if(res) return true;
        //如果当前节点是LCA，置结果res
        if((lson&&rson)||((x==p||x==q)&&(lson||rson))){
            res=x;
            return true;
        }
        //当前节点是否包含p或q
        return lson||rson||x==p||x==q;
    }
};

#endif //HOT100_236ADV_H
