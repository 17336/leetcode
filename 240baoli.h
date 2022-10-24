//
// Created by 17336 on 2021/11/5.
//

#ifndef HOT100_240BAOLI_H
#define HOT100_240BAOLI_H

#endif //HOT100_240BAOLI_H

#include "vector"
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (const auto &item: matrix[i]) {
                if(item==target) return true;
            }
        }
        return false;
    }
};