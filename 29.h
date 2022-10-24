//
// Created by 17336 on 2022/4/4.
//

#ifndef HOT100_29_H
#define HOT100_29_H

#include <algorithm>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        bool isNeg = (divisor > 0) != (dividend > 0);
        divisor = divisor>0?-divisor:divisor;
        dividend = dividend>0?-dividend:dividend;
        int res=0;
        while (dividend-divisor<=0){
            ++res;
            dividend-=divisor;
        }
        return isNeg?-res:res;
    }
};

#endif //HOT100_29_H
