//
// Created by 17336 on 2022/4/18.
//

#ifndef HOT100_440_H
#define HOT100_440_H

#include <iostream>

class Solution {
public:
    int findKthNumber(int n, int k) {
        int res = 1;
        while (--k > 0) {
            //可以通过在尾部加0实现   if (res * 10 <= n)会溢出，改为除法
            if (res <= n/10) res *= 10;
            //否则尝试在尾部加1，同时要保证没有进位，如：n=98991,res=98991,下一个res应该为99而非98992、9900等
            else{
                while (res+1>n||res%10==9) res/=10;
                ++res;
            }
        }
        return res;
    }
};

#endif //HOT100_440_H
