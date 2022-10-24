//
// Created by 17336 on 2021/11/30.
//

#ifndef HOT100_400_H
#define HOT100_400_H
#include "algorithm"
#include "cmath"
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        int i=0,x=9;
        long sum=0,last_sum=1;
        //判断n是i位数
        while (n>sum){
            last_sum=sum+1;
            sum+=++i*x;
            x*=10;
        }
        // x/90为最小的i位数，计算n所在位为哪一个i位数（可能是p也可能是p+1）
        int p=x/90+(n-last_sum+1)/i-1,q=(n-last_sum+1)%i;
        if(q==0) return p%10;
        else return (p+1)/(int) pow(10,i-q)%10;
    }
};

#endif //HOT100_400_H
