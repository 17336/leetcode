//
// Created by 17336 on 2021/12/17.
//

#ifndef HOT100_1518_H
#define HOT100_1518_H

#include "vector"

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty_bottle=0,sum=0;
        do {
            int temp=numBottles;
            //先把现在有的非空酒瓶喝了，变成空酒瓶
            sum+=numBottles;
            //用所有空酒瓶去换新酒
            numBottles=(empty_bottle+numBottles)/numExchange;
            //保存空酒瓶换剩下的空酒瓶
            empty_bottle=(empty_bottle+temp)%numExchange;
        } while (numBottles);
        return sum;
    }
};

#endif //HOT100_1518_H
