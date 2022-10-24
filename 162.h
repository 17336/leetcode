//
// Created by 17336 on 2022/4/8.
//

#ifndef HOT100_162_H
#define HOT100_162_H

#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            //若m是峰值
            if ((m == 0 || nums[m] > nums[m - 1]) && (m == nums.size() - 1 || nums[m] > nums[m + 1])) return m;
            //m不是峰值，则向递增的方向搜索
            else if (m > 0 && nums[m] < nums[m - 1]) r=m-1;
            else l=m+1;
        }
        return -1;
    }
};

#endif //HOT100_162_H
