//
// Created by 17336 on 2021/11/18.
//

#ifndef HOT100_85_H
#define HOT100_85_H

#endif //HOT100_85_H

#include "vector"

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        if(matrix.size()==0) return 0;
        int area=0;
        //矩形长宽、向上最大1、向左最大1
        vector<vector<vector<int>>> dp(matrix.size(),vector<vector<int>>(matrix[0].size()));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if(matrix[i][j]=='0'){
                    dp[i][j].push_back(0);
                    dp[i][j].push_back(0);
                    dp[i][j].push_back(0);
                    dp[i][j].push_back(0);
                    continue;
                }
                if(i==0&&j==0){
                    dp[i][j].push_back(1);
                    dp[i][j].push_back(1);
                    dp[i][j].push_back(1);
                    dp[i][j].push_back(1);
                }
                else if(i==0){
                    dp[i][j].push_back(dp[i][j-1][3]+1);
                    dp[i][j].push_back(1);
                    dp[i][j].push_back(1);
                    dp[i][j].push_back(dp[i][j-1][3]+1);
                }
                else if(j==0){
                    dp[i][j].push_back(1);
                    dp[i][j].push_back(dp[i-1][j][2]+1);
                    dp[i][j].push_back(dp[i-1][j][2]+1);
                    dp[i][j].push_back(1);
                }
                else {

                }
                area= max(area,dp[i][j].first*dp[i][j].second);
            }
        }
        return area;
    }
};