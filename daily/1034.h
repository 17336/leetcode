//
// Created by 17336 on 2021/12/7.
//

#ifndef HOT100_1034_H
#define HOT100_1034_H

#include "vector"

using namespace std;

class Solution {
    //保存需要替换的新颜色和原来的颜色
    int new_color,old_color;
    //分别向右下左上各走一步
    int step[5] = {0, 1, 0, -1, 0};
public:
    vector<vector<int>> colorBorder(vector<vector<int>> &grid, int row, int col, int color) {
        new_color = color;
        old_color=grid[row][col];
        //记录已访问过的结点
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size()));
        //深搜
        dfs(grid,visited,row,col);
        return grid;
    }

    void dfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int row, int col) {
        //如果已经访问过了
        if (visited[row][col]) return;
        //没访问过，那现在访问过了
        visited[row][col] = 1;
        for (int i = 0; i < 4; ++i) {
            //nr，nc为向右下左上各走一步后的新结点坐标
            int nr = row + step[i], nc = col + step[i + 1];
            //如果没出界
            if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[row].size()) {
                //还在连通分量范围内，则继续深搜
                if (grid[nr][nc] == old_color) dfs(grid, visited, nr, nc);
                //如果到达了新颜色，同时新颜色不是因为是本连通分量边界的新颜色（本连通分量的新颜色边界一定是原来访问过的visited）
                else if (!visited[nr][nc]) grid[row][col] = new_color;
            }
            //如果出界，同样到了连通分量边界
            else grid[row][col]=new_color;
        }
    }
};

#endif //HOT100_1034_H
