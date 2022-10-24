//
// Created by 17336 on 2022/2/24.
//

#ifndef HOT100_48_H
#define HOT100_48_H

#include "vector"

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                swap(matrix[i][j],matrix[i][n-1-j]);
            }
        }
    }
};

#endif //HOT100_48_H
