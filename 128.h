//
// Created by 17336 on 2022/4/7.
//

#ifndef HOT100_128_H
#define HOT100_128_H

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> set;
        for (const auto &num: nums) {
            set.insert(num);
        }
        int res=0;
        for (int i = 0; i < nums.size(); ++i) {
            if (set.count(nums[i])) {
                int t = 1, x = nums[i];
                while (set.count(++x)) {
                    ++t;
                    set.erase(x);
                }
                x = nums[i];
                while (set.count(--x)) {
                    ++t;
                    set.erase(x);
                }
                set.erase(nums[i]);
                res= max(res,t);
            }
        }
        return res;
    }
};

#endif //HOT100_128_H
