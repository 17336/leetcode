//
// Created by 17336 on 2021/12/1.
//

#ifndef HOT100_287_H
#define HOT100_287_H

#include "vector"
#include "cmath"

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        for (const auto &num: nums) {
            auto &temp = nums[abs(num)];
            if (temp < 0) return abs(num);
            temp = -temp;
        }
        for (auto &num: nums) {
            if (num < 0) num = -num;
        }
        return -1;
    }
};

#endif //HOT100_287_H
