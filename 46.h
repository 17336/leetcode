//
// Created by 17336 on 2021/11/4.
//

#ifndef HOT100_46_H
#define HOT100_46_H

#endif //HOT100_46_H

#include "vector"
using namespace std;

class Solution {
    vector<vector<int>> res;
    bool visited[21]={false};
public:
    vector <vector<int>> permute(vector<int> &nums) {
        vector<int> stack;
        backtrack(stack,nums);
        return res;
    }
    void backtrack(vector<int> &stack,vector<int> &nums){
        if(stack.size()==nums.size()){
            res.push_back(stack);
            return;
        }
        for (const auto &num: nums) {
            if(!visited[num+10]){
                stack.push_back(num);
                visited[num+10]= true;
                backtrack(stack,nums);
                visited[num+10]= false;
                stack.pop_back();
            }
        }
    }
};