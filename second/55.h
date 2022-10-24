//
// Created by 17336 on 2022/4/19.
//

#ifndef HOT100_55_H
#define HOT100_55_H

#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        //维护能跳到的最右下标
        int right=0;
        for (int i = 0; i < nums.size(); ++i) {
            if(i>right) return false;
            right= max(right,i+nums[i]);
        }
        return true;
    }
};

#endif //HOT100_55_H
