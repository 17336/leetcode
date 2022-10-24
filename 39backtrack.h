//
// Created by 17336 on 2021/11/8.
//

#ifndef HOT100_39BACKTRACK_H
#define HOT100_39BACKTRACK_H

#endif //HOT100_39BACKTRACK_H

#include "vector"
#include "algorithm"
using namespace std;

class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<int> stack;
        backtrack(candidates,stack,0,target);
        return res;
    }
    void backtrack(vector<int> &candidates,vector<int> &stack,int from,int tar){
        for (int i = from; i < candidates.size() ; ++i) {
            if(candidates[i]==tar){
                res.push_back(stack);
                res.back().push_back(candidates[i]);
                return;
            }
            else if(candidates[i]>tar) return;
            else {
                stack.push_back(candidates[i]);
                backtrack(candidates,stack,i,tar-candidates[i]);
                stack.pop_back();
            }
        }
    }
};