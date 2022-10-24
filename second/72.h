//
// Created by 17336 on 2022/3/30.
//

#ifndef HOT100_72_H
#define HOT100_72_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        //dp[i][j]表示word1长度为i的子串到word2长度为j的子串的距离
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, 0));
        //初始化：长度为0的串到任意长度为i的串距离都为i
        for (int i = 0; i <= word1.size(); ++i) {
            dp[i][0]=i;
        }
        for (int i = 0; i <= word2.size(); ++i) {
            dp[0][i]=i;
        }
        for (int i = 1; i <= word1.size(); ++i) {
            for (int j = 1; j <= word2.size(); ++j) {
                int a=dp[i][j-1]+1,b=dp[i-1][j]+1,c=dp[i-1][j-1]+(word1[i-1]==word2[j-1]?0:1);
                dp[i][j]= min(a, min(b,c));
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

#endif //HOT100_72_H
