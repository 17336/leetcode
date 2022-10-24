//
// Created by 17336 on 2021/12/8.
//

#ifndef HOT100_689ADV_H
#define HOT100_689ADV_H


#include "vector"
#include "deque"
using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k) {
        //维护一个dp备忘录，size为k+1；
        // dp[i]={ai1,ai2,bi1,bi2,ci1,ci2},ai1为一个最大子数组的起始下标,ai2为最大子数组和
        // bi1为两个最大子数组和，ci1为三个最大子数组和
        //deque<vector<int>> dp;

        vector<vector<int>> dp(nums.size(),vector<int>(9));
        //sum_k存储到当前位置i为止的连续k个元素之和
        int sum_k=0;
        for (int i = 0; i < nums.size(); ++i) {
            if(i+1<k){
                sum_k+=nums[i];
                continue;
            }
            else if(i+1==k){
                sum_k+=nums[i];
                dp[i][0]=i;
                dp[i][1]=sum_k;
                continue;
            }
            else{
                sum_k+=nums[i]-nums[i-k];
                if(sum_k>dp[i-1][1]) {
                    dp[i][0]=i;
                    dp[i][1]=sum_k;
                }
                else {
                    dp[i][0]=dp[i-1][0];
                    dp[i][1]=dp[i-1][1];
                }
            }
            if(i+1<2*k) continue;
            if(i+1==2*k){
                dp[i][2]=i-k;
                dp[i][3]=i;
                dp[i][4]=sum_k+dp[i-k][1];
                continue;
            }
            else if(sum_k+dp[i-k][1]>dp[i-1][4]){
                dp[i][2]=dp[i-k][0];
                dp[i][3]=i;
                dp[i][4]=sum_k+dp[i-k][1];
            }
            else{
                dp[i][2]=dp[i-1][2];
                dp[i][3]=dp[i-1][3];
                dp[i][4]=dp[i-1][4];
            }
            if(i+1<3*k) continue;
            if(i+1==3*k){
                dp[i][5]=i-2*k;
                dp[i][6]=i-k;
                dp[i][7]=i;
                dp[i][8]=sum_k+dp[i-k][4];
                continue;
            }
            else if(sum_k+dp[i-k][4]>dp[i-1][8]){
                dp[i][5]=dp[i-k][2];
                dp[i][6]=dp[i-k][3];
                dp[i][7]=i;
                dp[i][8]=sum_k+dp[i-k][4];
            }
            else {
                dp[i][5]=dp[i-1][5];
                dp[i][6]=dp[i-1][6];
                dp[i][7]=dp[i-1][7];
                dp[i][8]=dp[i-1][8];
            }
        }
        return {dp[nums.size()-1][5]-k+1,dp[nums.size()-1][6]-k+1,dp[nums.size()-1][7]-k+1};
    }
};

#endif //HOT100_689ADV_H
