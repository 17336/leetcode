//
// Created by 17336 on 2021/11/19.
//

#ifndef HOT100_283_H
#define HOT100_283_H

#endif //HOT100_283_H

#include "vector"

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //动态规划：访问到i时，last记录0~i-1中末尾0序列的第一个0下标
        int last=-1;
        for (int i = 0; i < nums.size(); ++i) {
            //如果还没遇到过0
            if(last==-1){
                //第一次遇到0
                if(nums[i]==0) last=i;
                //还没遇到0
                continue;
            }
            //如果last有0，交换
            else if(nums[i]){
                nums[last++]=nums[i];
                nums[i]=0;
            }
        }
    }
};