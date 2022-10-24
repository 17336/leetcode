//
// Created by 17336 on 2022/3/24.
//

#ifndef HOT100_53_H
#define HOT100_53_H

#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //前缀和：minSum维护一个最小的前缀和；sum维护当前前缀和
        int sum=0,res=INT_MIN,minSum=0;
        for (int i = 0; i < nums.size(); ++i) {
            sum+=nums[i];
            res= max(res,sum-minSum);
            minSum= min(minSum,sum);
        }
        return res;
    }
};

#endif //HOT100_53_H
