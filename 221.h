//
// Created by 17336 on 2021/11/17.
//

#ifndef HOT100_221_H
#define HOT100_221_H

#endif //HOT100_221_H

#include "vector"

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int Area = 0;
        //sum_one记录matrix矩形(0,0) (i,j)中1的数目
        vector<vector<char>> sum_one = matrix;
        for (int i = 0; i < matrix.size(); ++i) {
            //记录当前行到j的1的个数
            int row_sum = 0;
            for (int j = 0; j < matrix[i].size(); ++j) {
                row_sum += (matrix[i][j] - '0');
                if (i == 0) sum_one[i][j] = row_sum;
                else {
                    sum_one[i][j] = sum_one[i - 1][j] + row_sum;
                }
                int p = i, q = j;
                while (p >= 0 && q >= 0 &&
                       (sum_one[i][j] - (p == 0 ? 0 : sum_one[p - 1][j]) - (q == 0 ? 0 : sum_one[i][q - 1]) +
                        (((p != 0) && (q != 0)) ? sum_one[p - 1][q - 1] : 0)) == (j - q + 1) * (i - p + 1)) {
                    p--;
                    q--;
                }
                Area = max(Area, (j - q) * (i - p));
            }
        }
        return Area;
    }
};