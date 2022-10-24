//
// Created by 17336 on 2022/3/11.
//

#ifndef HOT100_300_H
#define HOT100_300_H

#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res=0;
        vector<int> dp;
        for (int i = 0; i < nums.size(); ++i) {
            int j=0,temp=0;
            while (j<i){
                if(nums[j]<nums[i]) temp= max(temp,dp[j]);
                ++j;
            }
            dp.push_back(temp+1);
            res= max(res,dp.back());
        }
        return res;
    }
};

#endif //HOT100_300_H
