//
// Created by 17336 on 2021/11/6.
//

#ifndef HOT100_268ADV1_H
#define HOT100_268ADV1_H

#endif //HOT100_268ADV1_H


#include "vector"

using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        unsigned long long sum1=nums.size(),sum2=0;
        for (int i = 0; i < nums.size(); ++i) {
            sum1+=i;
            sum2+=nums[i];
        }
        return sum1-sum2;
    }
};