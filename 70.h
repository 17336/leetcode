//
// Created by 17336 on 2021/11/7.
//

#ifndef HOT100_70_H
#define HOT100_70_H

#endif //HOT100_70_H


class Solution {
public:
    int climbStairs(int n) {
        int last=1,llast=0;
        for (int i = 2; i <= n; ++i) {
            int temp=last;
            last+=llast;
            llast=last;
        }
        return last;
    }
};