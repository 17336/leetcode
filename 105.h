//
// Created by 17336 on 2022/3/1.
//

#ifndef HOT100_105_H
#define HOT100_105_H

#include <vector>
#include "treenode.h"
#include <unordered_map>

using namespace std;

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
    unordered_map<int, int> map;
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            map[inorder[i]] = i;
        }
        return bTree(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }

    TreeNode *bTree(vector<int> &preorder, vector<int> &inorder, int pl, int pr, int inl, int inr) {
        TreeNode *root = new TreeNode(preorder[pl]);
        if (pl == pr) return root;
        int rootIndex = map[preorder[pl]];
        if (inl < rootIndex)
            root->left = bTree(preorder, inorder, pl + 1, pl + rootIndex - inl, inl, rootIndex - 1);
        if (inr > rootIndex)
            root->right = bTree(preorder, inorder, pl + rootIndex - inl + 1, pr, rootIndex + 1, inr);
        return root;
    }
};

#endif //HOT100_105_H
