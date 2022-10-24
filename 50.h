//
// Created by 17336 on 2021/12/5.
//

#ifndef HOT100_50_H
#define HOT100_50_H

class Solution {
public:
    double myPow(double x, int n) {
        long abs_n =n;
        if(n<0) abs_n=-(long)n;
        //维护结果sum
        double sum = 1;
        //不断更新x，直到超过abs_n最高位
        while (abs_n != 0) {
            //如果当前更新的x某次幂方是abs_n所需要的，添加到结果集中
            if (abs_n % 2) {
                sum *= x;
            }
            //更新x
            x *= x;
            //abs_n右移
            abs_n >>= 1;
        }
        if(n<0) return 1/sum;
        return sum;
    }
};

#endif //HOT100_50_H
