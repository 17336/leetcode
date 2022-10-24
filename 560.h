//
// Created by 17336 on 2021/11/2.
//

#ifndef HOT100_560_H
#define HOT100_560_H

#endif //HOT100_560_H

#include "vector"
#include "unordered_map"
using namespace std;
//前缀和算法
class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        //和为k的子数组个数为res
        int res=0;
        //dp[i]存储和为i的子数组个数
        unordered_map<int,int> dp;
        dp.emplace(0,1);
        //记录当前子数组和
        int sum=0;
        for (const auto &num: nums) {
            //更新sum
            sum+=num;
            //必须先查再插入sum，否则可能把空子数组算成和为0的有效子数组
            if(dp.count(sum-k)) res+=dp[sum-k];
            dp[sum]++;
        }
        return res;
    }
};