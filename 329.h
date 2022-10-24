//
// Created by 17336 on 2022/4/20.
//

#ifndef HOT100_329_H
#define HOT100_329_H

#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> memo;
    int steps[5] = {0, 1, 0, -1, 0};
    int m, n;
public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        m = matrix.size();
        n = matrix[0].size();
        memo.resize(m, vector<int>(n, -1));
        int res=0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res= max(longFrom(matrix,i,j),res);
            }
        }
        return res;
    }

    int longFrom(vector<vector<int>> &matrix, int i, int j) {
        if (memo[i][j] != -1) return memo[i][j];
        int cur=1;
        int maxNeighbor=0;
        for (int k = 0; k < 4; ++k) {
            int ni = i + steps[k], nj = j + steps[k + 1];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n &&matrix[ni][nj]>matrix[i][j]) {
                if (memo[ni][nj] == -1) {
                    maxNeighbor= max(maxNeighbor, longFrom(matrix, ni, nj));
                } else maxNeighbor= max(maxNeighbor, memo[ni][nj]);
            }
        }
        cur+=maxNeighbor;
        memo[i][j]=cur;
        return cur;
    }
};

#endif //HOT100_329_H
