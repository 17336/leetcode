//
// Created by 17336 on 2021/11/6.
//

#ifndef HOT100_268_H
#define HOT100_268_H

#endif //HOT100_268_H

#include "vector"
using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        vector<int> memo(nums.size()+1,0);
        for (const auto &num: nums) {
            memo[num]=1;
        }
        for (int i = 0; i < memo.size(); ++i) {
            if(memo[i]==0) return i;
        }
        return -1;
    }
};