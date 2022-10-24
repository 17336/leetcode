//
// Created by 17336 on 2022/3/28.
//

#ifndef HOT100_69_H
#define HOT100_69_H

class Solution {
public:
    int mySqrt(int x) {
        int res=0;
        while ((x<=4||res<x/2)&&(res+1)<=x/(res+1)){
            ++res;
        }
        return res;
    }
};

#endif //HOT100_69_H
