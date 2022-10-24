//
// Created by 17336 on 2022/5/11.
//

#ifndef HOT100_449_H
#define HOT100_449_H

#include <string>
#include <treenode.h>
#include <stack>
#include <queue>

using namespace std;

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string res;
        stack<TreeNode *> s;
        TreeNode *p = root;
        while (!s.empty() || p != nullptr) {
            if (p) {
                res.append(to_string(p->val));
                res.push_back(' ');
                s.push(p);
                p = p->left;
            } else {
                p = s.top();
                s.pop();
                p = p->right;
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        queue<int> nums;
        int i = 0, len = data.size();
        while (i < len) {
            int val = 0;
            while (data[i] != ' ') val = val * 10 + data[i++] - '0';
            ++i;
            nums.push(val);
        }
        return de(nums,INT_MIN,INT_MAX);
    }

    TreeNode *de(queue<int> &nums, int lower, int upper) {
        if (nums.empty() || nums.front() < lower || nums.front() > upper) return nullptr;
        TreeNode *head=new TreeNode(nums.front());
        nums.pop();
        head->left= de(nums,lower,head->val);
        head->right= de(nums,head->val,upper);
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

#endif //HOT100_449_H
