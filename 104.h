//
// Created by 17336 on 2021/11/15.
//

#ifndef HOT100_104_H
#define HOT100_104_H

#endif //HOT100_104_H

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
public:
    int maxDepth(TreeNode *root) {
        if(root) return deep(root,1);
        return 0;
    }

    int deep(TreeNode *root,int height){
        int now=height;
        if(root->left) now= deep(root->left,height+1);
        if(root->right) now = max(now, deep(root->right,height+1));
        return now;
    }
};