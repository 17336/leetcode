//
// Created by 17336 on 2022/3/26.
//

#ifndef HOT100_200_H
#define HOT100_200_H

#include <vector>

using namespace std;

class Solution {
    int steps[5] = {0, 1, 0, -1, 0};
    int m, n;
public:
    int numIslands(vector<vector<char>> &grid) {
        m = grid.size();
        n = grid[0].size();
        int res=0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if(grid[i][j]=='1'){
                    ++res;
                    dfs(grid,i,j);
                }
            }
        }
        return res;
    }

    //把与grid[i][j]相邻的陆地全都变为0
    void dfs(vector<vector<char>> &grid, int i, int j) {
        if (grid[i][j] != '1') return;
        grid[i][j]='0';
        for (int k = 0; k < 4; ++k) {
            int ni = i + steps[k], nj = j + steps[k + 1];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj]=='1'){
                dfs(grid,ni,nj);
            }
        }
    }
};

#endif //HOT100_200_H
