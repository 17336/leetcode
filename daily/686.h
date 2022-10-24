//
// Created by 17336 on 2021/12/22.
//

#ifndef HOT100_686_H
#define HOT100_686_H

#include "string"

using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int i=0,j=0,sum=0;
        while (i<a.size()){
            if(a[i]!=b[j]){
                i-=j-1;
                j=0;
                continue;
            }
            i++;
            j++;
            if(j==b.size()) return 1;
        }
        if(j==0) return -1;
        i=0;
        sum=1;
        return sum;
    }
    int func(string &a,string &b,int j){
        int i=0,sum=0;
        while (j<b.size()){
            if(a[i]!=b[j]) return -1;
            if(i==0) ++sum;
            i=(i+1)%a.size();
            ++j;
        }
        return sum;
    }
};

#endif //HOT100_686_H
