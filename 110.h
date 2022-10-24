//
// Created by 17336 on 2022/4/1.
//

#ifndef HOT100_110_H
#define HOT100_110_H

#include "treenode.h"
#include <algorithm>

using namespace std;

class Solution {
    //使用成员变量作为函数额外返回值，每次调用函数后主动来取返回值
    int height;
public:
    bool isBalanced(TreeNode *root) {
        if (root == nullptr) {
            height = 0;
            return true;
        }
        int lh, rh;
        if (!isBalanced(root->left)) return false;
        lh = height;
        if (!isBalanced(root->right)) return false;
        rh =height;
        if(abs(lh-rh)>1) return false;
        height= max(lh,rh) +1;
        return true;
    }
};

#endif //HOT100_110_H
