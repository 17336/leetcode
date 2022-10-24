//
// Created by 17336 on 2022/4/6.
//

#ifndef HOT100_112_H
#define HOT100_112_H

#include "treenode.h"

using namespace std;


class Solution {
public:
    bool hasPathSum(TreeNode *root, int targetSum) {
        if(root== nullptr) return false;
        return dfs(root,0,targetSum);
    }

    bool dfs(TreeNode *root, int sum, int target) {
        if (root->left == nullptr && root->right == nullptr) {
            if (sum + root->val == target) return true;
            return false;
        }
        return (root->left && dfs(root->left, sum + root->val, target)) ||
               (root->right && dfs(root->right, sum + root->val, target));
    }
};

#endif //HOT100_112_H
