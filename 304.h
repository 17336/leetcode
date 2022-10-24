//
// Created by 17336 on 2022/3/13.
//

#ifndef HOT100_304_H
#define HOT100_304_H

#include <vector>
#include <unordered_map>

using namespace std;

class NumMatrix {
    vector<vector<int>> map;
    int m;
    int n;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        m = matrix.size();
        n = matrix[0].size();
        vector<int> sums(n, 0);
        for (int i = 0; i < m; ++i) {
            map.emplace_back();
            int sum = 0;
            for (int j = 0; j < n; ++j) {
                sums[j] += matrix[i][j];
                sum += sums[j];
                map[i].push_back(sum);
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return map[row2][col2] - (row1>0?map[row1-1][col2]:0) - (col1>0?map[row2][col1-1]:0) + (row1 > 0 && col1 > 0
                                                                                                ? map[row1 - 1][col1 -
                                                                                                                1] : 0);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

#endif //HOT100_304_H
