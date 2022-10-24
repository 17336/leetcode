//
// Created by 17336 on 2021/11/22.
//

#ifndef HOT100_581_H
#define HOT100_581_H

#include "vector"

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int> &nums) {
        int ma = nums.front(), mi = nums.back();
        int r = -1, l = -1;
        //从左往右找最能干扰的最大值，同时找他能干扰到的最右边界处
        for (int i = 0; i < nums.size(); ++i) {
            ma = max(ma, nums[i]);
            if (nums[i] < ma) r = i;
        }
        //如果一项也干扰不到
        if (r == -1) return 0;
        //从右往左找最能干扰的最小值，同时找他能干扰到的最左边界处
        for (int i = nums.size() - 1; i >= 0; --i) {
            mi= min(mi,nums[i]);
            if(nums[i]>mi) l=i;
        }
        return r-l+1;
    }
};

#endif //HOT100_581_H
