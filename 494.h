//
// Created by 17336 on 2021/11/26.
//

#ifndef HOT100_494_H
#define HOT100_494_H

#include "vector"
#include "unordered_map"

using namespace std;

class Solution {
    int countTarget = 0;
    vector<int> sum;
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        sum.resize(nums.size());
        int temp=0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            temp+=nums[i];
            sum[i]=temp;
        }
        backtrack(nums, 0, target);
        return countTarget;
    }

    //回溯法，对i来说选择列表有+nums[i]和-nums[i]
    //如果i是最后一个数，选择结束，判断等于target
    void backtrack(vector<int> &nums, int i, int target) {
        if (i == nums.size() - 1) {
            if (target == nums[i]) countTarget++;
            if (target == -nums[i]) countTarget++;
            return;
        }
        //对下面注释进行优化
        if(target-nums[i]>=-sum[i+1]) backtrack(nums, i + 1, target - nums[i]);
        if(target+nums[i]<=sum[i+1])backtrack(nums, i + 1, target + nums[i]);
//        backtrack(nums, i + 1, target - nums[i]);
//        backtrack(nums, i + 1, target + nums[i]);
    }
};

#endif //HOT100_494_H
