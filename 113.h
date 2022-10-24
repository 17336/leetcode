//
// Created by 17336 on 2022/4/4.
//

#ifndef HOT100_113_H
#define HOT100_113_H

#include "treenode.h"
#include <vector>
#include <stack>

using namespace std;

class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        if (root == nullptr) return res;
        vector<int> path;
        dfs(root, path, 0, targetSum);
        return res;
    }

    void dfs(TreeNode *root, vector<int> &path, int sum, int target) {
        if (root->left == nullptr && root->right == nullptr) {
            if (sum + root->val == target) {
                res.emplace_back(path);
                res.back().push_back(root->val);
            }
            return;
        }
        path.push_back(root->val);
        if (root->left)
            dfs(root->left, path, sum + root->val, target);
        if (root->right)
            dfs(root->right, path, sum + root->val, target);
        path.pop_back();
    }
};

#endif //HOT100_113_H
