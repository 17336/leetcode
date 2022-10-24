//
// Created by 17336 on 2022/3/28.
//

#ifndef HOT100_TREEVISITED_H
#define HOT100_TREEVISITED_H

#include "treenode.h"
#include <stack>
#include <vector>

class Solution {
public:
    //中序遍历
    vector<int> inorderTraversal(TreeNode *root) {
        TreeNode *p = root;
        std::stack<TreeNode *> s;
        std::vector<int> res;
        //栈不为空或p不为空
        while (p != nullptr || !s.empty()) {
            //只要p不空，先入栈然后向左孩子搜索
            if (p) {
                s.push(p);
                p = p->left;
            }
                //p为空时，出栈并访问
            else {
                p = s.top();
                s.pop();
                res.push_back(p->val);
                p = p->right;
            }
        }
        return res;
    }

    //前序遍历
    vector<int> preorderTraversal(TreeNode *root) {
        TreeNode *p = root;
        std::stack<TreeNode *> s;
        std::vector<int> res;
        while (p != nullptr || !s.empty()) {
            if(p){
                res.push_back(p->val);
                s.push(p);
                p=p->left;
            } else{
                p=s.top();
                s.pop();
                p=p->right;
            }
        }
        return res;
    }
};

#endif //HOT100_TREEVISITED_H
