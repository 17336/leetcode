//
// Created by 17336 on 2021/11/26.
//

#ifndef HOT100_700_H
#define HOT100_700_H

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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root== nullptr||root->val==val) return root;
        if(root->val>val) return searchBST(root->left,val);
        if(root->val<val) return searchBST(root->right,val);
    }
};

#endif //HOT100_700_H
