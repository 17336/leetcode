//
// Created by 17336 on 2022/3/2.
//

#ifndef HOT100_124_H
#define HOT100_124_H

#include "treenode.h"
#include <algorithm>


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int straightMax;
public:
    int maxPathSum(TreeNode *root) {
        if (root == nullptr){
            straightMax = 0;
            return INT_MIN;
        }
        int left, right, sl, sr;
        left = maxPathSum(root->left);
        sl = straightMax;
        right = maxPathSum(root->right);
        sr = straightMax;
        straightMax= std::max(std::max(sl,sr),0)+root->val;
        return std::max(std::max(left,right),std::max(straightMax,sl+sr+root->val));
    }
};

#endif //HOT100_124_H
