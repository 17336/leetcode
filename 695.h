//
// Created by ByteDance on 2022/11/4.
//

#ifndef HOT100_695_H
#define HOT100_695_H

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int m,n;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int res=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]>0) res= max(res, dfs(grid,i,j));
            }
        }
        return res;
    }

    int dfs(vector<vector<int>> &grid,int i,int j){
        if(i<0||j<0||i>=m||j>=n||grid[i][j]<=0) return 0;
        grid[i][j]=-1;
        return 1+ dfs(grid,i+1,j)+ dfs(grid,i,j+1)+ dfs(grid,i-1,j)+ dfs(grid,i,j-1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_695_H
