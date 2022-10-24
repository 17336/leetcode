//
// Created by 17336 on 2021/11/9.
//

#ifndef HOT100_297_H
#define HOT100_297_H

#include "string"
#include "treenode.h"
#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string res;
        //空树返回空串
        if (root == nullptr) return res;
        //所有非空结点都按层序顺序入队；所有孩子节点如果非空则入队的同时将值插入res，如果为空不入队只插入'n'表示null
        //初始化根节点
        TreeNode *p = root;
        queue<TreeNode *> q;
        q.push(root);
        res.append(to_string(p->val));
        res.push_back(' ');
        //队列不为空，则访问其孩子
        while (!q.empty()) {
            int len = q.size();
            //一次访问一层
            for (int i = 0; i < len; ++i) {
                p = q.front();
                q.pop();
                //孩子不为空：入队+插值
                if (p->left) {
                    q.push(p->left);
                    res.append(to_string(p->left->val));
                    res.push_back(' ');
                }
                //孩子为空：只插值
                else {
                    res.append("n ");
                }
                if (p->right) {
                    q.push(p->right);
                    res.append(to_string(p->right->val));
                    res.push_back(' ');
                } else {
                    res.append("n ");
                }
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data == "") return nullptr;
        queue<TreeNode *> q;
        //字符串遍历位置
        size_t len = data.size();
        size_t pos = 0;
        //字符串转换int值
        int val = myStoi(data, &pos);
        //初始化根节点
        TreeNode *root = new TreeNode(val), *p;
        q.push(root);
        //每一个结点都从data中取出两个数用于初始化其孩子节点，再将非空孩子入队
        while (pos < len) {
            p = q.front();
            q.pop();
            //如果是null
            if (data[pos] == 'n') {
                pos += 2;
            } else {
                p->left = new TreeNode(myStoi(data, &pos));
                q.push(p->left);
            }
            if (pos >= len) break;
            if (data[pos] == 'n') pos += 2;
            else {
                p->right = new TreeNode(myStoi(data, &pos));
                q.push(p->right);
            }
        }
        return root;
    }

    //从*pos处将s转换为int，同时置pos为下一个起点
    int myStoi(string &s, size_t *pos) {
        size_t len = s.size();
        if (*pos >= len) return -1;
        int res = 0;
        bool isNeg= false;
        for (size_t i = *pos; i < len; ++i) {
            if(s[i]=='-'){
                isNeg= true;
                continue;
            }
            if (s[i] < '0' || s[i] > '9'){
                *pos=i+1;
                return isNeg?-res:res;
            }
            res=res*10+s[i]-'0';
        }
        return isNeg?-res:res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

#endif //HOT100_297_H

