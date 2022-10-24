//
// Created by 17336 on 2022/4/3.
//

#ifndef HOT100_230_H
#define HOT100_230_H

#include <treenode.h>
#include <stack>

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
public:
    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode *> s;
        TreeNode *p=root;
        while (p!= nullptr||!s.empty()){
            if(p){
                s.push(p);
                p=p->left;
            } else{
                p=s.top();
                s.pop();
                if(k--==1) return p->val;
                p=p->right;
            }
        }
        return -1;
    }
};

#endif //HOT100_230_H
