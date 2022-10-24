//
// Created by 17336 on 2021/11/4.
//

#ifndef HOT100_TREENODE_H
#define HOT100_TREENODE_H

#endif //HOT100_TREENODE_H


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};