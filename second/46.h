//
// Created by 17336 on 2022/3/16.
//

#ifndef HOT100_46_H
#define HOT100_46_H

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    vector<vector<int>> res;
    vector<int> visited;
public:
    vector<vector<int>> permute(vector<int> &nums) {
        visited.resize(nums.size());
        vector<int> path;
        backtrack(path, nums);
        return res;
    }

    //每一次函数调用对应回溯树中的一个节点
    void backtrack(vector<int> &path, vector<int> &nums) {
        //结束条件：path已加入nums所有元素
        if (path.size() == nums.size())
            res.push_back(path);
        //对于所有可选元素，选择并向下递归
        for (int i = 0; i < visited.size(); ++i) {
            if (!visited[i]) {
                //做出选择
                path.push_back(nums[i]);
                visited[i] = 1;
                backtrack(path, nums);
                //撤销选择
                visited[i] = 0;
                path.pop_back();
            }
        }
    }
};

#endif //HOT100_46_H
