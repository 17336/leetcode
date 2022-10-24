//
// Created by 17336 on 2022/4/5.
//

#ifndef HOT100_332_H
#define HOT100_332_H

#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); ++i) {
            for (int j = coins[i]; j <= amount; ++j) {
                if (dp[j - coins[i]] != -1) {
                    if (dp[j] == -1)
                        dp[j] = dp[j - coins[i]] + 1;
                    else dp[j]= min(dp[j],dp[j-coins[i]]+1);
                }
            }
        }
        return dp.back();
    }
};

#endif //HOT100_332_H
