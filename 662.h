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
        if(root== nullptr) return 0;
        int witdh = 1;
        TreeNode *p = root;
        std::queue<TreeNode *> q;
        q.push(p);
        //层序遍历模拟，树对应于满二叉树中的所有节点都要入队，nullptr结点也要入队
        while (!q.empty()) {
            int len = q.size();
            int i = 0;
            //beg,end分别记录下一层中最左最右的非空结点序号，count记录下一层总共多少个结点(宽度外的null节点也算)
            int beg = -1, end = -1, count = 0;
            for (; i < len; ++i) {
                p = q.front();
                q.pop();
                count+=1;
                if(p&&p->left){
                    if (beg == -1) beg = count;
                    end = count;
                    q.push(p->left);
                } else q.push(nullptr);
                count+=1;
                if(p&&p->right){
                    if (beg == -1) beg = count;
                    end = count;
                    q.push(p->right);
                } else q.push(nullptr);
            }
            if(beg==-1) return witdh;
            witdh = std::max(witdh, end - beg + 1);
        }
        return witdh;
    }
};

#endif //HOT100_662_H
