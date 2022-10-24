//
// Created by 17336 on 2022/3/19.
//

#ifndef HOT100_494ADV_H
#define HOT100_494ADV_H

#include <vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for (const auto &item: nums) {
            sum+=item;
        }
        if(sum<target||(sum-target)%2) return 0;
        int neg=(sum-target)/2;
        vector<int> dp(neg+1);
        dp[0]=1;
        //物品0~n-1,容量nums[0]~nums[n-1]
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = neg; j >=nums[i] ; --j) {
                dp[j]+=dp[j-nums[i]];
            }
        }
        return dp[neg];
    }
};

#endif //HOT100_494ADV_H
