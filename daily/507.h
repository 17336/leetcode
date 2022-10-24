//
// Created by 17336 on 2021/12/31.
//

#ifndef HOT100_507_H
#define HOT100_507_H

#include "algorithm"

using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num<=0) return false;
        if(num== sumFactor(num)) return true;
        return false;
    }
    int sumFactor(int num){
        int res=-num,i=1;
        for (; i*i < num; ++i) {
            if(num%i==0) res+=i+num/i;
        }
        if(i*i==num) res+=i;
        return res;
    }
};

#endif //HOT100_507_H
