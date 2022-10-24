//
// Created by 17336 on 2022/4/10.
//

#ifndef HOT100_863_H
#define HOT100_863_H

#include "treenode.h"
#include <vector>

using namespace std;

class Solution {
    vector<int> res;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root,target,k,0);
        return res;
    }

    //返回target结点的高度
    int dfs(TreeNode *root,TreeNode *target,int k,int height){
        if(root== nullptr) return -1;
        if(target==root){
            findNodeDist(root,k);
            return height;
        }
        int th=dfs(root->left,target,k,height+1);
        if(th!=-1){
            if(k-(th-height)==0) res.push_back(root->val);
            else findNodeDist(root->right,k-(th-height)-1);
            return th;
        }
        th= dfs(root->right,target,k,height+1);
        if(th!=-1){
            if(k-(th-height)==0) res.push_back(root->val);
            else findNodeDist(root->left,k-(th-height)-1);
            return th;
        }
        return -1;
    }

    //找到距离root dist的所有叶子节点
    void findNodeDist(TreeNode *root,int dist){
        if(root== nullptr||dist<0) return;
        if(dist==0) res.push_back(root->val);
        findNodeDist(root->left,dist-1);
        findNodeDist(root->right,dist-1);
    }
};

#endif //HOT100_863_H
