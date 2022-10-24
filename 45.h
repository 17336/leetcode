//
// Created by 17336 on 2022/5/12.
//

#ifndef HOT100_45_H
#define HOT100_45_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        int len = nums.size(), i = 0,reach=0,steps=0;
        while (reach < len - 1) {
            int right = reach;
            while (i <= reach) {
                right = max(right, i + nums[i]);
                ++i;
            }
            reach=right;
            ++steps;
        }
        return steps;
    }
};

#endif //HOT100_45_H
