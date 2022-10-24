//
// Created by 17336 on 2022/4/9.
//

#ifndef HOT100_152_H
#define HOT100_152_H

#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        if(nums.size()==1) return nums[0];
        int mp = 0, mPNeg = 0;
        int res=0;
        for (const auto &num: nums) {
            if (num > 0) {
                mp = max(num, mp * num);
                if(mPNeg) mPNeg*=num;
            } else if(num==0){
                mp=0;
                mPNeg=0;
            } else{
                int temp=mp;
                mp= max(mPNeg*num,0);
                mPNeg= min(num,temp*num);
            }
            res= max(res,mp);
        }
        return res;
    }
};

#endif //HOT100_152_H
