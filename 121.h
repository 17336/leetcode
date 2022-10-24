//
// Created by 17336 on 2021/11/7.
//

#ifndef HOT100_121_H
#define HOT100_121_H

#endif //HOT100_121_H

#include "vector"
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        int min_buy=prices[0],max_profit=0;
        for (int i = 1; i < prices.size(); ++i) {
            max_profit= max(max_profit,prices[i]-min_buy);
            min_buy= min(min_buy,prices[i]);
        }
        return max_profit;
    }
};