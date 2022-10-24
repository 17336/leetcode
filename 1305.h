//
// Created by 17336 on 2022/5/1.
//

#ifndef HOT100_1305_H
#define HOT100_1305_H

#include "treenode.h"
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
        TreeNode *p = root1, *q = root2;
        vector<int> res;
        stack<TreeNode *> s1, s2;
        while (p != nullptr || !s1.empty() || q != nullptr || !s2.empty()) {
            //只要p、q不为空就一直入栈，直到都为空，说明即将visit两棵树中结点，此时把较小值入res
            if (p == nullptr && q == nullptr) {
                if (s1.empty() || (!s2.empty() && s2.top()->val <= s1.top()->val)) {
                    q = s2.top();
                    s2.pop();
                    res.push_back(q->val);
                    q = q->right;
                } else {
                    p = s1.top();
                    s1.pop();
                    res.push_back(p->val);
                    p = p->right;
                }
            } else {
                if (p) {
                    s1.push(p);
                    p = p->left;
                }
                if (q) {
                    s2.push(q);
                    q = q->left;
                }
            }
        }
        return res;
    }
};

#endif //HOT100_1305_H
