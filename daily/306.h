//
// Created by 17336 on 2022/1/9.
//

#ifndef HOT100_306_H
#define HOT100_306_H

#include "string"
#include "math.h"

using namespace std;

class Solution {
    int len;
    int remain;
public:
    bool isAdditiveNumber(string num) {
        if(num.size()<3) return false;
        len = num.size();
        remain= pow(10,len)-1;
        int left=0,right=0,rEnd=1;
        for (int i = 0; i < len-2; ++i) {
            left=left*10+num[i]-'0';
            right=right- pow(10,rEnd-i)*(num[i]-'0');
            while (rEnd<len-1&&!backtrack(left,right,num,rEnd+1, pow(10,len-rEnd-2))){
                ++rEnd;

            }
        }
    }

    bool backtrack(int left,int right,string &num, int begin,int r) {
        int i = begin;
        int res = num[i] - '0';
        if(r< right+left)){
            return false;
        }
        while (i<len&&res<right+left){
            res=res*10+num[i++]-'0';
        }
        if(res!=right+left||(i<len-1&&num[i+1]=='0')) return false;
        return backtrack(right,res,num,i+1,remain/10);
    }
};

#endif //HOT100_306_H
