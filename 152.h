//
// Created by 17336 on 2021/11/8.
//

#ifndef HOT100_152_H
#define HOT100_152_H

#endif //HOT100_152_H

#include "vector"
#include "cmath"

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        if(nums.size()==1) return nums[0];
        int P_max = 0, N_max = 0, total_max = nums[0];
        for (const auto &num: nums) {
            if (num > 0) {
                P_max = max(num, num * P_max);
                N_max *= num;
            } else {
                int temp=P_max;
                P_max = num*N_max;
                N_max = min(num * temp,num);
            }
            total_max= max(total_max,P_max);
        }
        return total_max;
    }
};