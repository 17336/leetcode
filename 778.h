//
// Created by 17336 on 2022/3/27.
//

#ifndef HOT100_778_H
#define HOT100_778_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
    vector<vector<int>> visited;
    int steps[5] = {0, 1, 0, -1, 0},n;
public:
    int swimInWater(vector<vector<int>> &grid) {
        n = grid.size();
        visited.resize(n, vector<int>(n, 0));
        int l = 0, r = n * n, res = n * n;
        while (l <= r) {
            int mid = (l + r) / 2;
            fill(visited.begin(),visited.end(),vector<int> (n,0));
            if(canSwim(grid,0,0,mid)) {
                res= min(res,mid);
                r=mid-1;
            } else{
                l=mid+1;
            }
        }
        return res;
    }

    bool canSwim(vector<vector<int>> &grid, int i, int j, int x) {
        if (grid[i][j] > x) return false;
        if(i==n-1&&j==n-1) return true;
        visited[i][j] = 1;
        for (int k = 0; k < 4; ++k) {
            int ni = i + steps[k], nj = j + steps[k + 1];
            if (ni >= 0 && ni < n && nj >= 0 && nj < n && visited[ni][nj] == 0 &&
                canSwim(grid, ni, nj, x)) return true;
        }
        return false;
    }
};

#endif //HOT100_778_H
