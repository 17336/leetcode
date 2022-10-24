//
// Created by 17336 on 2021/11/13.
//

#ifndef HOT100_375ADV_H
#define HOT100_375ADV_H

#endif //HOT100_375ADV_H

#include "vector"
#include "climits"
using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        //dp[j][i]存储从j~i中猜中数字的最小金额数
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        //轮询每一个区间[j,i]
        for (int i = 1; i <=n ; ++i) {
            //这里逆序是因为[j,i]需要用到所有[j+1,i],[j+2,i]...
            for (int j = i-1; j >=1 ; --j) {
                int sum_min=INT_MAX;
                for (int k = j; k <= i; ++k) {
                    int temp=k+ max(dp[j][k-1],dp[k+1][i]);
                    sum_min= min(sum_min,temp);
                }
                dp[j][i]=sum_min;
            }
        }
        return dp[1][n];
    }
};