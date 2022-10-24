//
// Created by 17336 on 2021/11/15.
//

#ifndef HOT100_319_H
#define HOT100_319_H

#endif //HOT100_319_H

#include "vector"
#include "cmath"
using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        int sum=0;
        for (int i = 1; i*i <= n; ++i) {
            sum++;
        }
        return sum;
    }
};