//
// Created by 17336 on 2022/4/21.
//

#ifndef HOT100_240_H
#define HOT100_240_H

#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(),i = 0, j = n-1;
        while (i<m&&j>=0){
            if(matrix[i][j]==target) return true;
            if(matrix[i][j]>target) --j;
            else ++i;
        }
        return false;
    }
};

#endif //HOT100_240_H
