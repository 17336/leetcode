//
// Created by 17336 on 2021/11/21.
//

#ifndef HOT100_312BACKTRACK_H
#define HOT100_312BACKTRACK_H

#include "vector"

using namespace std;

class Solution {
    int sum=0;
public:
    int maxCoins(vector<int> &nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        solve(nums,0,nums.size()-1,dp);
        return dp[0][nums.size()-1];
    }
    int solve(vector<int> &nums,int i,int j,vector<vector<int>> &dp){
        if(dp[i][j]!=-1) return dp[i][j];
        if(i>=j-1) {
            return dp[i][j]=0;
        }
        int maxSum=0;
        for (int k = i+1; k < j; ++k) {
            int temp;
            if(maxSum<(temp=nums[k]*nums[i]*nums[j]+solve(nums,i,k,dp)+solve(nums,k,j,dp))){
                maxSum=temp;
            }
        }
        return dp[i][j]=maxSum;
    }
};

#endif //HOT100_312BACKTRACK_H

