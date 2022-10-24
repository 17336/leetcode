//
// Created by 17336 on 2021/11/26.
//

#ifndef HOT100_543_H
#define HOT100_543_H

#include "algorithm"

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
    int maxDiameter = 0;
public:
    int diameterOfBinaryTree(TreeNode *root) {
        height(root);
        return maxDiameter;
    }

    int height(TreeNode *root) {
        if (root == nullptr) return 0;
        int lh = 0, rh = 0;
        lh = height(root->left);
        rh = height(root->right);
        maxDiameter = max(maxDiameter, rh + lh);
        return max(lh, rh) + 1;
    }
};

#endif //HOT100_543_H
