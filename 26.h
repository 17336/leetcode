//
// Created by 17336 on 2022/4/1.
//

#ifndef HOT100_26_H
#define HOT100_26_H

#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        //k为重复元素个数
        int k = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if(nums[i]==nums[i-1]) {
                ++k;
                continue;
            }
            //不重复元素插入到nums[i-k]处
            nums[i-k]=nums[i];
        }
        return nums.size()-k;
    }
};

#endif //HOT100_26_H
