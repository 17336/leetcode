//
// Created by 17336 on 2022/3/17.
//

#ifndef HOT100_11_H
#define HOT100_11_H

#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res=0,l=0,r=height.size()-1;
        while (l<r){
            res= max(res, min(height[l],height[r])*(r-l));
            if(height[l]<height[r]) ++l;
            else --r;
        }
        return res;
    }
};

#endif //HOT100_11_H
