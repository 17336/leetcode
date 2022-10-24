//
// Created by 17336 on 2021/11/19.
//

#ifndef HOT100_397BIT_H
#define HOT100_397BIT_H

#endif //HOT100_397BIT_H

#include "algorithm"

using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        int count=0;
        while (n!=1){
            if(n%2==0){
                n>>=1;
                count++;
            }
            else if(n&3==3){
                n=(n+1l)/2;
                count+=2;
            }
            else {
                n>>=1;
                count+=2;
            }
        }
        return count;
    }
};