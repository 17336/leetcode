//
// Created by ByteDance on 2023/1/30.
//

#ifndef HOT100_958_H
#define HOT100_958_H

#include <queue>

//leetcode submit region begin(Prohibit modification and deletion)

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(!root) return true;
        std::queue<TreeNode *> q;
        q.push(root);
        TreeNode *p;

        while (!q.empty()) {
            p=q.front();
            q.pop();
            if(p->left) {
                q.push(p->left);
            }
            else if(p->right) {
                return false;
            }
            else break;
            if(p->right) {
                q.push(p->right);
            }
            else break;
        }
        while (!q.empty()) {
            p=q.front();
            if(p->left||p->right) return false;
            q.pop();
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_958_H
