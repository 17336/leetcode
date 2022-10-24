//
// Created by 17336 on 2021/11/25.
//

#ifndef HOT100_59_H
#define HOT100_59_H

#include "vector"

using namespace std;

class Solution {
    //分别向右、下、左、上走一步
    int step[5]={0,1,0,-1,0};
public:
    vector<vector<int>> generateMatrix(int n) {
        //结果矩阵
        vector<vector<int>> res(n,vector<int>(n));
        //累加数
        int start=1;
        //依次
        for (int i = 0; i < (n+1)/2; ++i) {
            start=func(res,i,i,n-2*i,start);
        }
        return res;
    }
    int func(vector<vector<int>> &res,int i,int j,int radius,int start){
        res[i][j]=start++;
        if(radius==1) {
            return 1;
        }
        for (int l = 0; l < 4; ++l) {
            for (int k = 0; k < radius-(l==3?2:1); ++k) {
                i+=step[l];
                j+=step[l+1];
                res[i][j]=start++;
            }
        }
        return start;
    }
};

#endif //HOT100_59_H
