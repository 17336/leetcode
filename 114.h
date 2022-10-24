//
// Created by 17336 on 2021/11/19.
//

#ifndef HOT100_114_H
#define HOT100_114_H

#endif //HOT100_114_H

#include "utility"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        func(root);
    }
    //func返回扁平化一颗二叉树之后的头节点和尾结点
    pair<TreeNode *,TreeNode *> func(TreeNode *root){
        if(root== nullptr) return {nullptr, nullptr};
        //temp1记录扁平化左子树后返回的头尾结点
        pair<TreeNode *,TreeNode *> temp1=func(root->left);
        //如果扁平化的左子树不是空树，把扁平化后的树嵌入到root右子树中间
        if(temp.first){
            root->left= nullptr;
            temp1.second->right=root->right;
            root->right=temp1.first;
        }
        //扁平化root原来的右子树
        pair<TreeNode *,TreeNode *> temp2=func(root->right);
        //返回root扁平化后的头尾
        return {root,temp2.second== nullptr?(temp1.second== nullptr?root:temp1.second):temp2.second};
    }
};