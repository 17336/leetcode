//
// Created by 17336 on 2021/11/7.
//

#ifndef HOT100_598_H
#define HOT100_598_H

#endif //HOT100_598_H

#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int row_min=m,line_min=n;
        //取所有加一区域中都重合的区域
        for (const auto &op: ops) {
            row_min= min(row_min,op.front());
            line_min= min(line_min,op.back());
        }
        return row_min*line_min;
    }
};