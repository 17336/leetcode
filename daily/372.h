//
// Created by 17336 on 2021/12/5.
//

#ifndef HOT100_372_H
#define HOT100_372_H

#include "vector"

using namespace std;

class Solution {
    int c = 1337;
public:
    int superPow(int a, vector<int> &b) {
        int res=1;
        a%=1337;
        for (int i = b.size() - 1; i >= 0; --i) {
            int temp= mypow(a,b[i]);
            res=res*temp%1337;
            a= mypow(a,10);
        }
        return res;
    }
    //快速幂算法的修正版，因为可能会溢出，所以我们在计算幂的同时直接利用余数性质
    int mypow(int a, int n) {
        int res = 1;
        while (n != 0) {
            if (n % 2) {
                res = res * x % 1337;
            }
            a = a * a % 1337;
            n >>= 1;
        }
        return res;
    }
};

#endif //HOT100_372_H
