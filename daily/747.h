//
// Created by 17336 on 2022/1/13.
//

#ifndef HOT100_747_H
#define HOT100_747_H

#include "vector"

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int fir,sec;
        if(nums[0]>nums[1]){
            fir=0;
            sec=1;
        }
        else {
            fir=1;
            sec=0;
        }
        for (int i = 2; i < nums.size(); ++i) {
            if(nums[i]>nums[fir]){
                sec=fir;
                fir=i;
            } else if(nums[i]>nums[sec]){
                sec=i;
            }
        }
        if(nums[fir]>=nums[sec]*2) return fir;
        return -1;
    }
};

#endif //HOT100_747_H
