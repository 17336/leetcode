//
// Created by 17336 on 2021/11/18.
//

#ifndef HOT100_563_H
#define HOT100_563_H

#endif //HOT100_563_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include "algorithm"
using namespace std;

class Solution {
    int tilt=0;
public:
    int findTilt(TreeNode *root) {
        func(root);
        return tilt;
    }
    int func(TreeNode *root){
        if (root == nullptr) return 0;
        int l=func(root->left),r=func(root->right);
        int sum=l+r+root->val;
        tilt+= abs(l-r);
        return sum;
    }
};