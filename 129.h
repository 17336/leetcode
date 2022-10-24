//
// Created by 17336 on 2022/4/1.
//

#ifndef HOT100_129_H
#define HOT100_129_H

#include "treenode.h"

class Solution {
public:
    int sumNumbers(TreeNode *root) {
        return dfs(root,0);
    }

    int dfs(TreeNode *root, int path) {
        if (root == nullptr) return path;
        path = path * 10 + root->val;
        int sum = 0;
        if (root->left == nullptr && root->right == nullptr) return path;
        if (root->left) sum += dfs(root->left, path);
        if (root->right) sum += dfs(root->right, path);
        return sum;
    }
};

#endif //HOT100_129_H
