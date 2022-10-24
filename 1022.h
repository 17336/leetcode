//
// Created by 17336 on 2022/5/30.
//

#ifndef HOT100_1022_H
#define HOT100_1022_H

#include <treenode.h>
#include <basi.h>

class Solution {
public:
    int sumRootToLeaf(TreeNode *root) {
        int res=0;
        queue<TreeNode *> q;
        TreeNode *p = root;
        q.push(p);
        while (!q.empty()) {
            p = q.front();
            q.pop();
            if (p->left == nullptr && p->right == nullptr) res += p->val;
            else {
                if(p->left){
                    p->left->val+=p->val*2;
                    q.push(p->left);
                }
                if(p->right){
                    p->right->val+=p->val*2;
                    q.push(p->right);
                }
            }
        }
        return res;
    }
};


#endif //HOT100_1022_H
