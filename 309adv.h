//
// Created by 17336 on 2021/11/6.
//

#ifndef HOT100_309ADV_H
#define HOT100_309ADV_H

#endif //HOT100_309ADV_H

#include "vector"

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //如果天数少，不能卖出
        if(prices.size()<2) return 0;
        int last_sell=0,max_sell=0;
        int max_buy=-prices[0];
        for (int i=1;i<prices.size();i++) {
            int a= max_sell;
            //维护子命题最大卖出
            max_sell= max(max_sell,last_sell);
            //情况1和情况2
            last_sell= max(last_sell,max_buy+prices[i]);
            //维护额外子命题最大买入
            max_buy= max(max_buy,a+prices[i]);
        }
        return last_sell;
    }
};