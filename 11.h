//
// Created by 17336 on 2021/11/10.
//

#ifndef HOT100_11_H
#define HOT100_11_H

#endif //HOT100_11_H

#include "vector"

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int i = 0, j = height.size() - 1,maxArea=0;
        while (i < j) {
            maxArea= max(maxArea,(j-i+1)* min(height[i],height[j]));
            if(height[i]<height[j]) i++
            else j--;
        }
        return maxArea;
    }
};