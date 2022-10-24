//
// Created by 17336 on 2021/12/12.
//

#ifndef HOT100_337_H
#define HOT100_337_H

#include "algorithm"
#include "unordered_map"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    //备忘录
    unordered_map<TreeNode *, int> memo;
public:
    int rob(TreeNode *root) {
        return recursive(root, true);
    }

    //求一棵树能偷到的最大钱数,stealable记录根节点让不让偷
    int recursive(TreeNode *root, bool stealable) {
        if (root == nullptr) return 0;
        //不偷root，只偷孩子节点，看最大能偷多少钱
        int child = recursive(root->left, true) + recursive(root->right, true);
        //如果root本来就不让偷，直接返回child
        if (!stealable) return child;
        //如果root让偷，查询原来是否偷过，没偷则偷一次试试，并记忆化保存；偷过直接用原来的值
        if (memo.count(root)) return memo[root];
        return memo[root]=max(child, root->val + recursive(root->left, false) + recursive(root->right, false));
    }
};

#endif //HOT100_337_H
