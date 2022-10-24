//
// Created by 17336 on 2021/11/11.
//

#ifndef HOT100_55_H
#define HOT100_55_H

#endif //HOT100_55_H

#include "vector"

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last=0;
        for (int i = 0; i <=last ; ++i) {
            last= max(last,i+nums[i]);
            if(last>=nums.size()-1) return true;
        }
        return false;
    }
};