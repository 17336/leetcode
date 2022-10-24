//
// Created by 17336 on 2022/5/8.
//

#ifndef HOT100_61_H
#define HOT100_61_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isStraight(vector<int> &nums) {
        sort(nums.begin(), nums.end(), less<int>());
        int zero = 0, i = 0;
        while (nums[i] == 0) ++i;
        tost
        zero = i;
        while (i < 5) {
            if (i > 0 && nums[i - 1] != 0) {
                if (nums[i] == nums[i - 1]) return false;
                if (nums[i - 1] + 1 != nums[i]) zero -= nums[i] - nums[i - 1] - 1;
            }
            if (zero < 0) return false;
            ++i;
        }
        return true;
    }
};

#endif //HOT100_61_H
