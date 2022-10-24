//
// Created by 17336 on 2022/3/23.
//

#ifndef HOT100_5_H
#define HOT100_5_H

#include <vector>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int temp= swapRec(nums,i);
            if(temp!=-1) return temp;
        }
        return -1;
    }

    //递归将nums[i]对号入座到位置nums[nums[i]]，如果已经在座位上则不用换位置了；如果位置上有同一个元素则重复，不同元素递归
    int swapRec(vector<int> &nums,int i){
        if(nums[i]==i) return -1;
        if(nums[nums[i]]==nums[i]) return nums[i];
        swap(nums[i],nums[nums[i]]);
        return swapRec(nums,i);
    }
};

#endif //HOT100_5_H
