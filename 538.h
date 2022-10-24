//
// Created by 17336 on 2021/11/15.
//

#ifndef HOT100_538_H
#define HOT100_538_H

#endif //HOT100_538_H


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    int sum=0;
public:
    TreeNode* convertBST(TreeNode* root) {
        if(root){
            convertBST(root->right);
            sum+=root->val;
            root->val=sum;
            convertBST(root->left);
        }
        return root;
    }
};