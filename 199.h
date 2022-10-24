//
// Created by 17336 on 2022/3/28.
//

#ifndef HOT100_199_H
#define HOT100_199_H

#include "treenode.h"
#include <queue>

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        TreeNode *p=root;
        std::queue<TreeNode *> q;
        q.push(p);
        std::vector<int> res;
        if(root== nullptr) return res;
        while (!q.empty()){
            res.push_back(q.back()->val);
            int len=q.size();
            for (int i = 0; i < len; ++i) {
                p=q.front();
                q.pop();
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
        }
        return res;
    }
};

#endif //HOT100_199_H
