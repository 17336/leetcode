//
// Created by 17336 on 2021/11/6.
//

#ifndef HOT100_309_H
#define HOT100_309_H

#endif //HOT100_309_H

#include "vector"

using namespace std;

class Solution {

public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2) return 0;
        //dp[i]存储加入第i天之后的最大股票收益
        vector<int> dp(prices.size(), 0);
        //第1天及之后的每一天都可能成为卖出的那一天
        for (int i = 1; i < prices.size(); ++i) {
            //第i天既有可能卖出、也有可能第i天不卖出产生最大收益
            dp[i]=dp[i-1];//初始化为第i天不卖出的最大收益
            //判断第i天卖出时可能的最大收益，可以从第j天买入判断
            for (int j = 0; j <= i - 1; ++j) {
                if (j  >= 3)dp[i] = max(dp[j - 2] + prices[i] - prices[j],dp[i]);
                else dp[i]= max(prices[i] - prices[j],dp[i]);
            }
        }
        return dp[prices.size()-1];
    }
};