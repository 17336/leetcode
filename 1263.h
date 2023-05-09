//
// Created by le.zhang on 2023/5/9.
//

#ifndef HOT100_1263_H
#define HOT100_1263_H

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    int steps[5] = {0, 1, 0, -1, 0};
public:
    int minPushBox(vector<vector<char>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-2));
        vector<vector<int>> visited(m,vector<int> (n,0));
        vector<vector<int>> canMove(m,vector<int> (n,0));
        int x1,y1,x2,y2;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if(grid[i][j]=='B') {
                    x1=i;
                    y1=j;
                }
                if(grid[i][j]=='S') {
                    x2=i;
                    y2=j;
                }
            }
        }
        dps(grid,x2,y2,canMove);
        if(canMove[x1][y1]==0) return -1;
        return minPushBox(grid,dp,visited,canMove,x1,y1);
    }

    void dps(vector<vector<char>> &grid,int x,int y,vector<vector<int>> &canMove) {
        canMove[x][y]=1;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < 4; ++i) {
            int nx = x + steps[i], ny = y + steps[i + 1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && canMove[nx][ny]==0 &&grid[nx][ny] != '#') {
                dps(grid,nx,ny,canMove);
            }
        }
    }

    int minPushBox(vector<vector<char>> &grid, vector<vector<int>> &dp, vector<vector<int>> &visited,
                   vector<vector<int>> &canMove, int x, int y) {
        if (dp[x][y] >= -1) return dp[x][y];
        if (grid[x][y] == 'T') return dp[x][y] = 0;
        int m = grid.size(), n = grid[0].size();
        int res=-1;
        for (int i = 0; i < 4; ++i) {
            int nx = x + steps[i], ny = y + steps[i + 1];
            int px = 2 * nx - x, py = 2 * ny - y;
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && visited[nx][ny]==0 &&grid[nx][ny] != '#' &&
                px >= 0 && px < m && py >= 0 && py < n && canMove[px][py]) {
                visited[nx][ny]=1;
                int t= minPushBox(grid,dp,visited,canMove,nx,ny);
                if(t!=-1) res= min(res,t+1);
                visited[nx][ny]=0;
            }
        }
        return dp[x][y]=res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_1263_H
