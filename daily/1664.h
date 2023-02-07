//
// Created by ByteDance on 2023/1/28.
//

#ifndef HOT100_1664_H
#define HOT100_1664_H

#include <vector>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int waysToMakeFair(std::vector<int> &nums) {
        int lodd = 0, leven = 0, rf = 0, rs = 0, len = nums.size();
        for (int i = 0; i < len; ++i) {
            if (i % 2) rs += nums[i];
            else rf += nums[i];
        }
        int res = 0;
        for (int i = 0; i < len; ++i) {
            if (i > 0) {
                if (i % 2) {
                    leven += nums[i-1];
                } else {
                    lodd += nums[i-1];
                }
            }
            int temp = rf;
            rf = rs;
            rs = temp - nums[i];
            res+=((lodd+(i%2?rf:rs)) == (leven+(i%2?rs:rf)));
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_1664_H
