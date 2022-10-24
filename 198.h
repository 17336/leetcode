//
// Created by 17336 on 2022/3/5.
//

#ifndef HOT100_198_H
#define HOT100_198_H

#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int fir= nums[0],sec= max(nums[0],nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            int temp=fir;
            fir=sec;
            sec= max(temp+nums[i],sec);
        }
        return sec;
    }
};

#endif //HOT100_198_H
