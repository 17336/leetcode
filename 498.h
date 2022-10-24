//
// Created by 17336 on 2022/4/11.
//

#ifndef HOT100_498_H
#define HOT100_498_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
        vector<vector<int>> steps{{-1, 1},
                                  {1,  -1}};
        vector<int> res;
        int i = 0, j = 0, m = mat.size(), n = mat[0].size();
        int sf = 0;
        while (i < m && j < n) {
            res.push_back(mat[i][j]);
            int ni = i + steps[sf][0], nj = j + steps[sf][1];
            //注意应该优先检查右边界和下边界，因为反对角线可能同时超出右上、左下，以右、下为准
            //超出右边界
            if (nj >= n) {
                ++i;
                sf = (sf + 1) % 2;
            }
            //超出下边界
            else if(ni>=m){
                ++j;
                sf = (sf + 1) % 2;
            }
            //超出左边界
            else if(nj < 0){
                ++i;
                sf = (sf + 1) % 2;
            }
            //超出上边界
            else if(ni < 0){
                ++j;
                sf = (sf + 1) % 2;
            }
            //没超出边界
            else {
                i = ni;
                j = nj;
            }
        }
        return res;
    }
};

#endif //HOT100_498_H
