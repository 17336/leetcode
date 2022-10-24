//
// Created by 17336 on 2022/3/20.
//

#ifndef HOT100_ZPRINTTREE_H
#define HOT100_ZPRINTTREE_H

#include "treenode.h"
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> Print(TreeNode *pRoot) {
        //Z字形访问结果集
        vector<vector<int>> res;
        if (pRoot == nullptr) return res;
        //用栈保存每层节点：结点插入顺序和访问顺序相反
        std::stack<TreeNode *> s;
        s.push(pRoot);
        TreeNode *p;
        //判断这次是先入左孩子还是先入右孩子
        bool isReverse = false;
        while (!s.empty()) {
            int len = s.size();
            res.emplace_back();
            //临时插入栈
            stack<TreeNode *> temp;
            for (int i = 0; i < len; ++i) {
                p = s.top();
                s.pop();
                res.back().emplace_back(p->val);
                if (isReverse) {
                    if (p->right) temp.push(p->right);
                    if (p->left) temp.push(p->left);
                } else {
                    if (p->left) temp.push(p->left);
                    if (p->right) temp.push(p->right);
                }
            }
            //将临时栈的数据挪回正式栈
            s.swap(temp);
            //每次改变入栈顺序
            isReverse = !isReverse;
        }
        return res;
    }
};

#endif //HOT100_ZPRINTTREE_H
