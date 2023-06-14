//
// Created by le.zhang on 2023/5/17.
//

#ifndef HOT100_343_H
#define HOT100_343_H

#include <unordered_map>

class Solution {
    std::unordered_map<int,int> m;
public:
    int integerBreak(int n) {
        int res=0;
        for (int i = 1; i < n; ++i) {
            res=std::max(res, iBreak(n-i)*i);
        }
        return res;
    }

    int iBreak(int n) {
        if(m.count(n)) return m[n];
        int res=n;
        for (int i = 1; i < n; ++i) {
            res=std::max(res,i* iBreak(n-i));
        }
        m[n]=res;
        return res;
    }
};

#endif //HOT100_343_H
