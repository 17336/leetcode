//
// Created by 17336 on 2021/11/6.
//

#ifndef HOT100_268ADV_H
#define HOT100_268ADV_H

#endif //HOT100_268ADV_H

#include "vector"

using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int x=0;
        //对0~n异或一次，对nums[0]~nums[n-1]异或一次，那么出现1次的数异或了2次，出现0次的数异或了1次
        for (int i = 0; i < nums.size(); ++i) {
            x^=(i^nums[i]);
        }
        x^=nums.size();
        return x;
    }
};