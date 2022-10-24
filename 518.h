//
// Created by 17336 on 2022/4/14.
//

#ifndef HOT100_518_H
#define HOT100_518_H

#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int> &coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        int n = coins.size();
        for (int i = 0; i < n; ++i) {
            for (int j = coins[i]; j <= amount; ++j) {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};

#endif //HOT100_518_H
