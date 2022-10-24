//
// Created by 17336 on 2021/11/5.
//

#ifndef HOT100_240_H
#define HOT100_240_H

#endif //HOT100_240_H

#include "vector"

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        //target可能在的矩阵      l_row~r_row
        //                up_row   ......
        //                   |     ......
        //                dow_row  ......
        //逐渐缩小矩阵的范围
        int l_row=0,r_row=matrix[0].size()-1;
        int up_row=0,down_row=matrix.size()-1;
        int mid1,mid2;
        while (l_row<=r_row&&up_row<=down_row){
            if(matrix[up_row][l_row]==target) return true;
            //缩小r_row的范围
            int temp=l_row;
            while (r_row>=l_row){
                mid1=(l_row+r_row)/2;
                if(matrix[up_row][mid1]<=target&&(mid1==matrix[0].size()-1||matrix[up_row][mid1+1]>target)) {
                    r_row=mid1;
                    if(matrix[up_row][mid1]==target) return true;
                    break;
                }
                else if(matrix[up_row][mid1]>target) r_row=mid1-1;
                else {
                    l_row=mid1+1;
                }
            }
            if(r_row<l_row) return false;
            l_row=temp;

            //缩小down_row的范围
            temp=up_row;
            while (down_row>=up_row){
                mid2=(up_row+down_row)/2;
                if(matrix[mid2][l_row]<=target&&(mid2==matrix.size()-1||matrix[mid2+1][l_row]>target)) {
                    down_row=mid2;
                    if(matrix[mid2][l_row]==target) return true;
                    break;
                }
                else if(matrix[mid2][l_row]>target) down_row=mid2-1;
                else {
                    up_row=mid2+1;
                }
            }
            if(down_row<up_row) return false;
            up_row=temp;
            //缩小l_row,up_row
            l_row++;
            up_row++;
        }
        return false;
    }
};