//
// Created by 17336 on 2022/3/9.
//

#ifndef HOT100_236_H
#define HOT100_236_H

#include "treenode.h"
#include <stack>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    std::stack<TreeNode *> path1;
    std::stack<TreeNode *> path2;
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        TreeNode *pNode = root, *last = nullptr;
        int find = 0;
        while (!path1.empty() || pNode != nullptr) {
            if (pNode) {
                path1.push(pNode);
                if (pNode == p || pNode == q) {
                    if (find == 0) {
                        path2 = path1;
                        ++find;
                    } else {
                        break;
                    }
                }
                pNode = pNode->left;
            } else {
                pNode = path1.top();
                //右子树没有访问过
                if (pNode->right && pNode->right != last) {
                    pNode = pNode->right;
                } else {
                    path1.pop();

                    last = pNode;
                    pNode = nullptr;
                }
            }
        }
        while (path1.top() != path2.top()) {
            if (path1.size() > path2.size()) {
                path1.pop();
            } else path2.pop();
        }
        return path1.top();
    }
};

#endif //HOT100_236_H
