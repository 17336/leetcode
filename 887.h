//
// Created by 17336 on 2022/5/6.
//

#ifndef HOT100_887_H
#define HOT100_887_H

#include <vector>

using namespace std;

class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1));
        //初始化边界
        for (int i = 1; i < n + 1; ++i) {
            dp[1][i] = i;
        }
        for (int i = 2; i < k + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                //二分查找最优best
                int left = 1, right = j, best = -1;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (dp[i][j - mid] > dp[i - 1][mid - 1]) {
                        best=mid;
                        left=mid+1;
                    } else if(dp[i][j - mid] < dp[i - 1][mid - 1]){
                        right=mid-1;
                    } else {
                        best=mid;
                        break;
                    }
                }
                dp[i][j]=1+ max(dp[i-1][best-1],dp[i][j-best]);
            }
        }
        return dp[k][n];
    }
};

#endif //HOT100_887_H
