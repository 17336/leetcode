//
// Created by 17336 on 2022/4/8.
//

#ifndef HOT100_153_H
#define HOT100_153_H

#include <vector>

using namespace std;


class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0,r=nums.size()-1;
        while (l<=r){
            int m=(l+r)/2;
            //如果[l,r]已经有序，直接返回最小值
            if(nums[r]>=nums[m]&&nums[m]>=nums[l]) return nums[l];
            //如果是旋转点，一定是最小值
            if(m>0&&nums[m-1]>nums[m]) return nums[m];
            //否则在无序部分搜索
            if(nums[m]>=nums[l]) l=m+1;
            else r=m-1;
        }
        return -1;
    }
};

#endif //HOT100_153_H
