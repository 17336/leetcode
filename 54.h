//
// Created by 17336 on 2022/3/26.
//

#ifndef HOT100_54_H
#define HOT100_54_H

#include <vector>

using namespace std;

class Solution {
    int steps[5] = {0, 1, 0, -1, 0};
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        //水平方向步数n，垂直方向步数m
        int sep1 = n, sep2 = m - 1;
        //模拟走的路径，起点在[0,-1]
        int begin1=0,begin2=-1;
        //只要还有步数可以走
        while (sep1 > 0 || sep2 > 0) {
            //每一轮四个方向都要走
            for (int j = 0; j < 4; ++j) {
                //temp保存本次要走的步数
                int temp;
                //奇数代表垂直方向
                if (j % 2) {
                    temp = sep2--;
                }
                //偶数代表水平方向
                else {
                    temp = sep1--;
                }
                for (int k = 0; k < temp; ++k) {
                    begin1+=steps[j];
                    begin2+=steps[j+1];
                    res.push_back(matrix[begin1][begin2]);
                }
                //细节:当一轮只剩一行或一列数据时，则本轮遍历完结束
                if((j%2==1&&sep1==0)||(j%2==0&&sep2==0)) return res;
            }
        }
        return res;
    }
};

#endif //HOT100_54_H
