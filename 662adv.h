//
// Created by 17336 on 2022/3/21.
//

#ifndef HOT100_662_H
#define HOT100_662_H

#include "treenode.h"
#include <queue>

class Solution {
public:
    int widthOfBinaryTree(TreeNode *root) {
        if (root == nullptr) return 0;
        long witdh = 1;
        TreeNode *p = root;
        //队列q存储结点指针和对应于满二叉树中的序号
        std::queue<pair<TreeNode *, int>> q;
        q.push({p, 1});
        //还是层序遍历，但是不用将null结点入队了，直接用满二叉树的序号确定位置
        while (!q.empty()) {
            int len = q.size();
            int i = 0;
            //beg,end分别记录下一层中最左最右的非空结点序号
            long beg = -1, end = -1;
            for (; i < len; ++i) {
                p = q.front().first;
                long num = q.front().second;
                q.pop();
                if (p->left) {
                    end=2*num;
                    if (beg == -1) beg = end;
                    q.push({p->left, end});
                }
                if (p->right) {
                    end=2*num+1;
                    if (beg == -1) beg = end;
                    q.push({p->right, end});
                }
            }
            witdh = std::max(witdh, end - beg + 1);
        }
        return witdh;
    }
};

#endif //HOT100_662_H
