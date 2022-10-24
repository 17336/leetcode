//
// Created by 17336 on 2022/4/15.
//

#ifndef HOT100_62_H
#define HOT100_62_H

class Solution {
public:
    int lastRemaining(int n, int m) {
        //最后一轮剩余数下标为num
        int res = 0;
        //逆推上一轮下标，直到第一轮
        for (int i = 2; i <= n; ++i) {
            res = (res + m) % i;
        }
        return res;
    }
};

#endif //HOT100_62_H
