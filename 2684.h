//
// Created by le.zhang on 2023/5/17.
//

#ifndef HOT100_2684_H
#define HOT100_2684_H

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    int m;
    int n;
public:
    int maxMoves(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>> dps(m,vector<int> (n,-1));
        int res=0;
        for (int i = 0; i < m; ++i) {
            res= max(maxMoves(grid,i,0,dps),res);
        }
        return res;
    }

    int maxMoves(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dps) {
        if (dps[i][j]!= -1) return dps[i][j];
        if(j==n-1) return dps[i][j]=0;
        int res=0;
        if (i-1>=0&&grid[i-1][j+1]>grid[i][j]) {
            res= max(res,1+ maxMoves(grid,i-1,j+1,dps));
        }
        if (grid[i][j+1]>grid[i][j])
            res= max(res,1+ maxMoves(grid,i,j+1,dps));
        if (i+1<m&&grid[i+1][j+1]>grid[i][j])
            res= max(res,1+ maxMoves(grid,i+1,j+1,dps));
        return dps[i][j]=res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2684_H
