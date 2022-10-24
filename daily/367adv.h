//
// Created by 17336 on 2021/11/4.
//

#ifndef HOT100_367ADV_H
#define HOT100_367ADV_H

#endif //HOT100_367ADV_H

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int i=1;
        while (num>0){
            //采用减法判断是否可能与一个数列和相等
            num-=2*i++-1;
        }
        if(num==0) return true;
        return false;
    }
};