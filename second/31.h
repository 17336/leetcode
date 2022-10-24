//
// Created by 17336 on 2022/3/29.
//

#ifndef HOT100_31_H
#define HOT100_31_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        if (nums.size() == 1) return;
        int j = nums.size() - 1;
        while (j > 0 && nums[j - 1] >= nums[j]) {
            --j;
        }
        if (j == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int i = j - 1;
        while (j < nums.size()-1 && nums[j + 1] > nums[i])++j;
        swap(nums[i],nums[j]);
        sort(nums.begin()+i+1,nums.end());
    }
};

#endif //HOT100_31_H
