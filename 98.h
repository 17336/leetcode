//
// Created by 17336 on 2021/11/15.
//

#ifndef HOT100_98_H
#define HOT100_98_H

#endif //HOT100_98_H


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    TreeNode *last= nullptr;
public:
    bool isValidBST(TreeNode* root) {
        if(root){
            if(!isValidBST(root->left))return false;
            if(last!= nullptr&&root->val<=last->val) return false;
            last=root;
            return isValidBST(root->right);
        }
        return true;
    }
};