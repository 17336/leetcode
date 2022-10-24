//
// Created by 17336 on 2022/3/6.
//

#ifndef HOT100_200_H
#define HOT100_200_H

#include <vector>

using namespace std;

class Solution {
    int count = 0;
public:
    int numIslands(vector<vector<char>> &grid) {
        int res=0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if(grid[i][j]=='1') {
                    ++res;
                    dfs(grid,i,j);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>> &grid, int i, int j) {
        if (i < grid.size() - 1 && grid[i + 1][j] == '1') {
            grid[i + 1][j] = '2';
            dfs(grid, i + 1, j);
        }
        if (j < grid[i].size() - 1 && grid[i][j + 1] == '1') {
            grid[i][j + 1] = '2';
            dfs(grid, i, j + 1);
        }
        if (i > 0 && grid[i-1][j]=='1'){
            grid[i-1][j]='2';
            dfs(grid,i-1,j);
        }
        if(j>0&&grid[i][j-1]=='1'){
            grid[i][j-1]='2';
            dfs(grid,i,j-1);
        }
    }
};

#endif //HOT100_200_H
