//
// Created by 17336 on 2022/4/3.
//

#ifndef HOT100_122_H
#define HOT100_122_H

#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int res = 0;
        vector<int> dp(prices.size(), 0);
        for (int i = 1; i < prices.size(); ++i) {
            dp[i] = dp[i - 1];
            if (prices[i - 1] < prices[i]) dp[i]=dp[i-1]+prices[i]-prices[i-1];
        }
        return dp.back();
    }
};

#endif //HOT100_122_H
