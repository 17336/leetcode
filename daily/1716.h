//
// Created by 17336 on 2022/1/15.
//

#ifndef HOT100_1716_H
#define HOT100_1716_H

class Solution {
public:
    int totalMoney(int n) {
        int week = n / 7, res = 0;
        for (int i = 1; i <= week; ++i) {
            res += (i + 3) * 7;
        }
        res+=(2*week+n%7+1)*(n%7)/2;
        return res;
    }
};

#endif //HOT100_1716_H
