//
// Created by 17336 on 2022/4/7.
//

#ifndef HOT100_1094ADV_H
#define HOT100_1094ADV_H

#include <vector>

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>> &trips, int capacity) {
        vector<int> nums(1001,0);
        //对于所有区间，左边界上车trip[0]人，右边界下车trip[0]人
        for (const auto &trip: trips) {
            nums[trip[1]]+=trip[0];
            nums[trip[2]]-=trip[0];
        }

        //对于[0,1000]所有上下车位置，实时维护车上人数
        int people=0;
        for (int i = 0; i < 1001; ++i) {
            people+=nums[i];
            if(people>capacity) return false;
        }
        return true;
    }
};

#endif //HOT100_1094ADV_H
