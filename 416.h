//
// Created by 17336 on 2021/11/21.
//

#ifndef HOT100_416_H
#define HOT100_416_H

#endif //HOT100_416_H

#include "vector"
#include "algorithm"
#include "numeric"

using namespace std;

class Solution {
public:
    //01-bag问题，检查是否能从序列nums中挑选出一个和为Σnums/2的子集
    bool canPartition(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;
        int target = sum / 2;
        //设置dp数组，dp[j]存放遍历当前nums[i]后，能否从1~i中找到和为j的子集
        vector<int> dp(target + 1, 0);\
        dp[0] = 1;
        //先遍历nums序列（物品）
        for (const auto &num: nums) {
            //后遍历每一个容量（从target往前到num，以免覆盖原数据）
            for (int i = target; i >= num; --i) {
                //如果不用选num就可以找到和为j，或者选num后可以找到和为j，则置一
                if (dp[i] || dp[i - num]) dp[i] = 1;
            }
            //找到则提前退出
            if (dp[target]) return true;
        }
        return false;
    }
};