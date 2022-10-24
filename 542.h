//
// Created by 17336 on 2022/3/17.
//

#ifndef HOT100_542_H
#define HOT100_542_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
    int steps[5] = {0, 1, 0, -1, 0};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> res(mat.size(), vector<int>(mat[0].size(), -1));

        //BFS初始化队列为所有0结点
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!mat[i][j]) {
                    res[i][j]=0;
                    q.emplace(i, j);
                }
            }
        }

        //找图中剩余节点到0结点的距离
        int dist = 1;
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; ++i) {
                int k = q.front().first, j = q.front().second;
                q.pop();
                for (int l = 0; l < 4; ++l) {
                    int x = k + steps[l], y = j + steps[l + 1];
                    if (x < m && x >= 0 && y < n && y >= 0 && res[x][y] == -1) {
                        res[x][y] = dist;
                        q.emplace(x,y);
                    }
                }
            }
            ++dist;
        }
        return res;
    }
};

#endif //HOT100_542_H
