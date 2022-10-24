//
// Created by 17336 on 2021/11/7.
//

#ifndef HOT100_279_H
#define HOT100_279_H

#endif //HOT100_279_H

#include "vector"
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        //动态规划：加入i之后可能从i-1、i-4、i-9、i-16......加上一个完全平方数上来
        //即dp[i]=min(dp[i-1],dp[i-4],dp[i-9]...)+1
        vector<int> dp(n+1,10000);
        int x=1;
        //保存比当前i小的所有完全平方数
        vector<int> square;
        for (int i = 1; i < n; ++i) {
            if(x*x==i) {
                square.push_back(i);
                dp[i]=1;
                x++;
                continue;
            }
            else{
                for (const auto &item: square) {
                    dp[i]= min(dp[i],dp[i-item]+1);
                    if(dp[i]==2) break;
                }
            }
        }
        return dp[n];
    }
};