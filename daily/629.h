//
// Created by 17336 on 2021/11/11.
//

#ifndef HOT100_629_H
#define HOT100_629_H

#endif //HOT100_629_H

#include "algorithm"
#include "vector"
using namespace std;

class Solution {
public:
    int kInversePairs(int n, int k) {
        //0个逆序对即有序排序
        if(k==0) return 1;
        int mod=1000000007;
        vector<long long > dp(k+1,0);
        //产生0个逆序对个数为1
        dp[0]=1;
        vector<long long > now=dp;
        //考虑加入第i个数如何求k个逆序对的排列个数？考虑所有可能的第i个数的插入位置，插入后有可能多出来0~i-1个逆序对
        for (int i = 2; i <= n; ++i) {
            long long sum=dp[0];
            //求j个逆序对的排列个数
            for (int j = 1; j <= k; ++j) {
                if(j>=i) {
                    sum+=(dp[j]-dp[j-i])%mod;
                }
                else {
                    sum+=dp[j]%mod;
                }
                now[j]=sum;
            }
            dp.swap(now);
        }
        return dp[k]%mod;
    }
};