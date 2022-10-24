//
// Created by 17336 on 2022/5/30.
//

#ifndef HOT100_111_H
#define HOT100_111_H

#include <basi.h>

class Solution {
public:
    int minDepth(TreeNode *root) {
        if(root== nullptr) return 0;
        TreeNode *p = root;
        queue<TreeNode *> q;
        q.push(p);
        int m = 0;
        while (!q.empty()) {
            int len = q.size();
            ++m;
            for (int i = 0; i < len; ++i) {
                p = q.front();
                q.pop();
                if (p->left == nullptr && p->right == nullptr) return m;
                if (p->left) q.push(p->left);
                if (p->right) q.push(p->right);
            }
        }
        return -1;
    }
};

#endif //HOT100_111_H
