//
// Created by ByteDance on 2023/1/17.
//

#ifndef HOT100_1814_H
#define HOT100_1814_H

#include <vector>
#include <unordered_map>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    void computeCounts(std::unordered_map<int, int> &rev_counts, std::vector<int> &nums) {
        for (auto num: nums) {
            int rev_num = 0, temp = num;
            while (num != 0) {
                rev_num = rev_num * 10 + num % 10;
                num /= 10;
            }
            ++rev_counts[temp - rev_num];
        }
    }

public:
    int countNicePairs(std::vector<int> &nums) {
        std::unordered_map<int, int> rev_counts;
        computeCounts(rev_counts, nums);
        int res = 0;
        for (const auto &item: rev_counts) {
            res = (res + 1ll*item.second * (item.second - 1) / 2) % 1000000007;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_1814_H
