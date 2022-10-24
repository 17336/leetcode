//
// Created by 17336 on 2021/12/4.
//

#ifndef HOT100_169_H
#define HOT100_169_H

#include "vector"

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int count=0,res=nums[0];
        //遍历元素序列nums
        for (const auto &num: nums) {
            //当count==0，重新选一个候选人num并计数
            if(count==0) {
                res=num;
                count++;
            }
            //如果选到的同为res
            else if(num==res) count++;
            //如果选到的不是res
            else {
                count--;
            }
        }
        return res;
    }
};

#endif //HOT100_169_H
