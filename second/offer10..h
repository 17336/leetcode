//
// Created by 17336 on 2022/3/21.
//

#ifndef HOT100_OFFER10_H
#define HOT100_OFFER10_H

class Solution {
public:
    int numWays(int n) {
        if(n<=1) return 1;
        int last=1,llast=1;
        for (int i = 2; i <= n; ++i) {
            int temp=llast;
            llast=last;
            last=(temp%1000000007+last%1000000007)%1000000007;
        }
        return last;
    }
};

#endif //HOT100_OFFER10_H
