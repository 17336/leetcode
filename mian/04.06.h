//
// Created by 17336 on 2022/5/16.
//

#ifndef HOT100_04_06_H
#define HOT100_04_06_H

#include "treenode.h"
#include <stack>

using namespace std;

class Solution {
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        TreeNode *q = root;
        stack<TreeNode *> s;
        bool flag= false;
        while (!s.empty() || q) {
            if(q){
                s.push(q);
                q=q->left;
            } else{
                q=s.top();
                s.pop();
                if(flag) return q;
                if(q->val==p->val) flag= true;
                q=q->right;
            }
        }
        return nullptr;
    }
};

#endif //HOT100_04_06_H
