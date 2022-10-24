//
// Created by 17336 on 2021/11/7.
//

#ifndef HOT100_279MATH_H
#define HOT100_279MATH_H

#endif //HOT100_279MATH_H


#include "cmath"
#include "vector"

using namespace std;

class Solution {
    bool isSquares(int x) {
        int a = sqrt(x);
        return a * a == x;
    }

public:
    int numSquares(int n) {
        int temp;
        for (int i = 0; 7 * (temp=exp2(2 * i)) <= n ; ++i) {
            if(n%temp==0&&(n/temp-7)%8==0) return 4;
        }
        if(isSquares(n)) return 1;
        for (int i = 0; i*i < n; ++i) {
            if(isSquares(n-i*i)) return 2;
        }
        return 3;
    }
};