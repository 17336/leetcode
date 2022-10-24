//
// Created by 17336 on 2021/11/12.
//

#ifndef HOT100_375_H
#define HOT100_375_H

#endif //HOT100_375_H

#include "vector"
#include "climits"

using namespace std;

class Solution {
    //dp[i]存储1~i确保获胜的最小现金数和两条路对应猜测次数
    static vector<vector<int>> dp;
public:
    int getMoneyAmount(int n) {
        int len = dp.size();
        for (int i = len; i <= n; ++i) {
            int sum = INT_MAX, count = 0;
            for (int j = (1 + i) / 2; j < i; ++j) {
                int temp1 = max(dp[j - 1][0], dp[i - j][1] + dp[i - j].second * j) + j;
                if (temp1 < sum) {
                    sum = temp1;
                    count = max(dp[j - 1].second, dp[i - j].second) + 1;
                }
            }
            dp.push_back({sum, count});
        }
        return dp[n].first;
    }
};

vector<vector<int>> Solution::dp{{0, 0, 0, 0},
                                 {0, 0, 0, 0}};