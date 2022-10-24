//
// Created by 17336 on 2022/3/28.
//

#ifndef HOT100_94_H
#define HOT100_94_H

#include "treenode.h"
#include <stack>
#include <vector>

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode *p=root;
        std::stack<TreeNode *>s;
        std::vector<int> res;
        while (p!= nullptr||!s.empty()){
            if(p){
                s.push(p);
                p=p->left;
            } else{
                p=s.top();
                s.pop();
                res.push_back(p->val);
                p=p->right;
            }
        }
        return res;
    }
};

#endif //HOT100_94_H
