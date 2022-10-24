//
// Created by 17336 on 2021/11/10.
//

#ifndef HOT100_32_H
#define HOT100_32_H

#endif //HOT100_32_H

#include "string"

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int i=0,j=0;
        int lenM=0;
        int lbra=0;
        for (; j <s.size(); ++j) {
            if(s[j]=='(') lbra++;
            else lbra--;
            if(lbra<0){
                lenM= max(lenM,j-i);
                lbra=0;
                i=j+1;
            }
        }
        if(lbra==0) lenM= max(lenM,j-i);
        i=s.size()-1;
        j=s.size()-1;
        int rbra=0;
        for (; j >=0; --j) {
            if(s[j]==')') rbra++;
            else rbra--;
            if(rbra<0){
                lenM= max(lenM,i-j);
                rbra=0;
                i=j-1;
            }
        }
        if(rbra==0) lenM= max(lenM,i-j);
        return lenM;
    }
};