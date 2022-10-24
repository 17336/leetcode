//
// Created by 17336 on 2021/12/25.
//

#ifndef HOT100_1609_H
#define HOT100_1609_H

#include "../useful/treenode.h"
#include "queue"
#include "climits"

using namespace std;

class Solution {
public:
    bool isEvenOddTree(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *p = root;
        int level = 0;
        while (!q.empty()) {
            int len = q.size(), last;
            if (level % 2) {
                last=INT_MAX;
                for (int i = 0; i < len; ++i) {
                    if (q.front()->val % 2 || q.front()->val >= last) return false;
                    last = q.front()->val;
                    if (q.front()->left) q.push(q.front()->left);
                    if (q.front()->right) q.push(q.front()->right);
                    q.pop();
                }
            }
            else {
                last=0;
                for (int i = 0; i < len; ++i) {
                    if (q.front()->val % 2 == 0 || q.front()->val <= last) return false;
                    last = q.front()->val;
                    if (q.front()->left) q.push(q.front()->left);
                    if (q.front()->right) q.push(q.front()->right);
                    q.pop();
                }
            }
            level += 1;
        }
        return true;
    }
};

#endif //HOT100_1609_H
