//
// Created by 17336 on 2021/12/29.
//

#ifndef HOT100_1995_H
#define HOT100_1995_H

#include "vector"
#include "unordered_map"

using namespace std;

//1 1 1 3 6 5
class Solution {
public:
    int countQuadruplets(vector<int> &nums) {
        int res=0;
        for (int i = 3; i < nums.size(); ++i) {
            res+= func(nums,i-1,nums[i]);
        }
        return res;
    }

    int func(vector<int> &nums, int end, int target) {
        int sum = 0;
        for (int i = 0; i <= end - 2; ++i) {
            if(nums[i]>target-2) continue;
            for (int j = i + 1; j <= end - 1; ++j) {
                if(nums[j]+nums[i]>target-1) continue;
                for (int k = j+1; k <= end; ++k) {
                    if(nums[i]+nums[j]+nums[k]==target) ++sum;
                }
            }
        }
        return sum;
    }
};

#endif //HOT100_1995_H
