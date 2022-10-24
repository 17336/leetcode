//
// Created by 17336 on 2021/11/4.
//


#ifndef HOT100_367_H
#define HOT100_367_H

#endif //HOT100_367_H
#include "stdexcept"
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        int left=1,right=num/2,mid;
        while (left<right) {
            mid=(left+right)/2;
            //用除法判断是否相等
            if(num%mid==0&&num/mid==mid) return true;
            //用除法判断平方是大了还是小了
            if(num/mid<mid) right=mid-1;
            else left=mid+1;
        }
        return false;
    }
};