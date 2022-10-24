//
// Created by 17336 on 2021/11/17.
//

#ifndef HOT100_221DP_H
#define HOT100_221DP_H

#endif //HOT100_221DP_H

#include "vector"

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int maxLen=0;
        //dp[i][j]依次存储(i,j)为右下角端点的矩形最大边长、(i,j)向上最大1个数、(i,j)向左最大1个数
        vector<vector<vector<int>>> dp;
        for (int i = 0; i < matrix.size(); ++i) {
            dp.push_back({});
            for (int j = 0; j < matrix[i].size(); ++j) {
                dp[i].push_back({});
                if(matrix[i][j]=='0'){
                    dp[i][j].push_back(0);
                    dp[i][j].push_back(0);
                    dp[i][j].push_back(0);
                    continue;
                }
                int row_one=0,col_one=0,len=0;
                if(i==0&&j==0){
                    row_one=1;
                    col_one=1;
                    len=1;
                }
                else if(i==0){
                    row_one=dp[i][j-1][2]+1;
                    col_one=1;
                    len=1;
                }
                else if(j==0){
                    row_one=1;
                    col_one=dp[i-1][j][1]+1;
                    len=1;
                }
                else {
                    row_one=dp[i][j-1][2]+1;
                    col_one=dp[i-1][j][1]+1;
                    len= min(min(col_one,row_one),dp[i-1][j-1][0]+1);
                }
                maxLen= max(maxLen,len);
                dp[i][j].push_back(len);
                dp[i][j].push_back(col_one);
                dp[i][j].push_back(row_one);
            }
        }
        return maxLen*maxLen;
    }
};