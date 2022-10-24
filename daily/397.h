//
// Created by 17336 on 2021/11/19.
//

#ifndef HOT100_397_H
#define HOT100_397_H

#endif //HOT100_397_H

#include "algorithm"

using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        //递归出口
        if(n==2) return 1;
        if(n==1) return 0;
        //如果是奇数，返回从n+1、n-1转换次数较小的那一方
        if(n%2){
            //为了防止n+1溢出，将n+1转换为long类型n+1l
            return min(integerReplacement((n+1l)/2), integerReplacement((n-1)/2))+2;
        }
        return integerReplacement(n/2)+1;
    }
};