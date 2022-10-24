//
// Created by 17336 on 2022/2/26.
//

#ifndef HOT100_64_H
#define HOT100_64_H

#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if(i==m-1&&j==n-1)continue;
                int down = INT_MAX, right = INT_MAX;
                if (i != m - 1) down = grid[i + 1][j];
                if (j != n - 1) right = grid[i][j + 1];
                grid[i][j] += min(down, right);
            }
        }
        return grid[0][0];
    }
};

#endif //HOT100_64_H
