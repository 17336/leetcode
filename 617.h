//
// Created by 17336 on 2021/11/20.
//

#ifndef HOT100_617_H
#define HOT100_617_H

#endif //HOT100_617_H


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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1&&root2){
            root1->val+=root2->val;
            if(root1->left) mergeTrees(root1->left,root2->left);
            else if(root2->left) root1->left=root2->left;
            if(root1->right) mergeTrees(root1->right,root2->right);
            else root1->right=root2->right;
        }
        if(root1) return root1;
        return root2;
    }
};