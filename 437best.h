//
// Created by 17336 on 2021/11/16.
//

#ifndef HOT100_437BEST_H
#define HOT100_437BEST_H

#endif //HOT100_437BEST_H

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
    int sum = 0;
    unordered_map<int, int> memo{{0, 1}};
public:
    int pathSum(TreeNode *root, int targetSum) {
        dfs(root,0,targetSum);
        return sum;
    }
    void dfs(TreeNode *root,int state,int targetSum){
        if(root){
            sum+=memo[state+root->val-targetSum];
            memo[state+root->val]++;
            dfs(root->left,state+root->val,targetSum);
            dfs(root->right,state+root->val,targetSum);
            memo[state+root->val]--;
        }
        else {
            sum+=memo[targetSum];
        }
    }
};