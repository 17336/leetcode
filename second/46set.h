//
// Created by 17336 on 2022/3/16.
//

#ifndef HOT100_46SET_H
#define HOT100_46SET_H

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        //选择列表
        unordered_set<int> set(nums.begin(),nums.end());
        //path记录已选元素
        vector<int> path;
        backtrack(set,path);
        return res;
    }

    //每一次函数调用对应回溯树中的一个节点
    void backtrack(unordered_set<int> &set,vector<int> &path){
        //
        for (const auto &item: set) {
            path.push_back(item);
            set.erase(item);
            backtrack(set,path);
            set.insert(item);
            path.pop_back();
        }
        res.push_back(path);
    }
};

#endif //HOT100_46SET_H
