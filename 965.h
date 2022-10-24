//
// Created by 17336 on 2022/5/24.
//

#ifndef HOT100_965_H
#define HOT100_965_H

#include <treenode.h>
#include <queue>
using namespace std;

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        int x=root->val;
        queue<TreeNode *> q;
        TreeNode *p=root;
        q.push(p);
        while (!q.empty()){
            p=q.front();
            q.pop();
            if(p->val!=x) return false;
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
        }
        return true;
    }
};

#endif //HOT100_965_H
