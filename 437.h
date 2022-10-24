//
// Created by 17336 on 2021/11/16.
//

#ifndef HOT100_437_H
#define HOT100_437_H

#endif //HOT100_437_H


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    int sum = 0;
public:
    int pathSum(TreeNode *root, int targetSum) {
        if(root){
            backtrack(root,0,targetSum);
            pathSum(root->left,targetSum);
            pathSum(root->right,targetSum);
        }
        return sum;
    }

    void backtrack(TreeNode *root,int state,int targetSum){
        if(root){
            state+=root->val;
            if(state==targetSum) sum++;
            backtrack(root->left,state,targetSum);
            backtrack(root->right,state,targetSum);
        }
    }
};