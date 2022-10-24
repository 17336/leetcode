//
// Created by 17336 on 2022/4/1.
//

#ifndef HOT100_105_H
#define HOT100_105_H

#include <treenode.h>
#include <vector>

using namespace std;

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildT(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }

    TreeNode *buildT(vector<int> &preoder, int l1, int r1, vector<int> &inorder, int l2, int r2) {
        if (l1 > r1) return nullptr;
        if (l1 == r1) return new TreeNode(preoder[l1]);
        TreeNode *head = new TreeNode(preoder[l1]);
        int i=l2;
        while (inorder[i]!=preoder[l1]) ++i;
        head->left= buildT(preoder,l1+1,l1+i-l2,inorder,l2,i-1);
        head->right= buildT(preoder,r1-r2+i+1,r1,inorder,i+1,r2);
        return head;
    }
};

#endif //HOT100_105_H
