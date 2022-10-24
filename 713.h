//
// Created by 17336 on 2022/5/5.
//

#ifndef HOT100_713_H
#define HOT100_713_H

#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        int status = 1, left = 0, res = 0;
        //右边界尽量右移
        for (int right = 0; right < nums.size(); ++right) {
            //更新窗口状态
            status *= nums[right];
            //不满足条件时，左边界右移
            while (left <= right && status >= k) {
                status /= nums[left];
                ++left;
            }
            //计算所有满足条件的连续子集
            res+=right-left+1;
        }
        return res;
    }
};

#endif //HOT100_713_H
