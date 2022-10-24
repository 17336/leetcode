//
// Created by 17336 on 2022/5/31.
//

#ifndef HOT100_556_H
#define HOT100_556_H

#include <basi.h>

class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> num;
        while (n){
            num.push_back(n%10);
            n/=10;
        }
        int i = 0,len=num.size();
        for (;i < len-1; ++i) {
            if(num[i]>num[i+1]) break;
        }
        if(i==len-1) return -1;
        int j=i;
        while (j>=1&&num[j-1]>num[i+1]) --j;
        swap(num[i+1],num[j]);
        sort(num.begin(),num.begin()+i+1,greater<int>());
        long res=0;
        for (int k = len-1; k >=0; --k) {
            res=res*10+num[k];
        }
        if(res>INT_MAX) return -1;
        return res;
    }
};

#endif //HOT100_556_H
