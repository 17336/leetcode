//
// Created by 17336 on 2022/3/23.
//

#ifndef HOT100_5ADV2_H
#define HOT100_5ADV2_H

#include <vector>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int> &nums) {
        int n=nums.size();
        for (int i = 0; i < n; ++i) {
            int cur=(nums[i]<0?-nums[i]:nums[i])%n;
            if(nums[cur]<0) return cur;
            if(nums[cur]==0) nums[cur]=-n;
            else nums[cur]=-nums[cur];
        }
        return -1;
    }
};

#endif //HOT100_5ADV2_H
