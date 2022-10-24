//
// Created by 17336 on 2022/3/14.
//

#ifndef HOT100_53_H
#define HOT100_53_H

#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        //sum维护到当前i结尾的最大子数组和
        int res = nums[0], sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            //如果sum<0，抛弃前面的sum，重新从nums[i]开始
            if (sum < 0) sum = nums[i];
            else sum += nums[i];
            res = max(res, sum);
        }
        return res;
    }
};

#endif //HOT100_53_H
