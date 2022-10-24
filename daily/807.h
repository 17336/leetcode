//
// Created by 17336 on 2021/12/13.
//

#ifndef HOT100_807_H
#define HOT100_807_H

#include "vector"
#include "array"

using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid) {
        vector<int> vertical(grid.size(),0),horizontal(grid.size(),0);
        for (int i = 0; i < grid.size(); ++i) {
            int hormax = INT_MIN;
            for (int j = 0; j < grid[i].size(); ++j) {
                hormax = max(hormax, grid[i][j]);
                vertical[j]= max(vertical[j],grid[i][j]);
            }
            horizontal[i] = hormax;
        }
        int sum = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                sum += min(horizontal[i], vertical[j]) - grid[i][j];
            }
        }
        return sum;
    }
};

#endif //HOT100_807_H
