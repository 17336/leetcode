//
// Created by 17336 on 2022/4/1.
//

#ifndef HOT100_16_H
#define HOT100_16_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0]+nums[1]+nums[2];
        for (int i = 0; i < nums.size() - 2; ++i) {
            int j = i + 1, k = nums.size() - 1;
            int sum=nums[i] + nums[j] + nums[k];
            while (j < k) {
                if(sum==target) return target;
                if (abs(sum - target) < abs(res - target)) res=sum;
                if(sum<target) ++j;
                else --k;
                sum = nums[i] + nums[j] + nums[k];
            }
        }
        return res;
    }
};

#endif //HOT100_16_H
