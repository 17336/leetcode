//
// Created by 17336 on 2021/12/3.
//

#ifndef HOT100_238_H
#define HOT100_238_H

#include "vector"

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> output;
        int mul = 1;
        output.push_back(1);
        for (int i = 1; i < nums.size(); ++i) {
            mul*=nums[i-1];
            output.push_back(mul);
        }
        mul=1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            mul*=nums[i+1];
            output[i]*=mul;
        }
        return output;
    }
};

#endif //HOT100_238_H
