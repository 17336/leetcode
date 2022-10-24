//
// Created by 17336 on 2021/11/5.
//

#ifndef HOT100_240ADV_H
#define HOT100_240ADV_H

#endif //HOT100_240ADV_H

#include "vector"

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int i=0,j=matrix[0].size()-1;
        while (i<matrix.size()&&j>=0){
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]>target) j--;
            else i++;
        }
        return false;
    }
};