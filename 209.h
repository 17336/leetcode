//
// Created by 17336 on 2022/3/13.
//

#ifndef HOT100_209_H
#define HOT100_209_H

#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int sum = 0, left = 0, res = INT_MAX;
        //右边界右移使之满足>=target
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            //左边界尽可能右移，使数组长度尽可能小，同时还要维持条件>=target
            while (left < i && sum - nums[left] >= target) {
                sum -= nums[left++];
            }
            if (sum >= target) res = min(res, i - left + 1);
        }
        return res==INT_MAX?0:res;
    }
};

#endif //HOT100_209_H
