//
// Created by 17336 on 2022/4/3.
//

#ifndef HOT100_292_H
#define HOT100_292_H

class Solution {
public:
    bool canWinNim(int n) {
        if(n==1||n==2||n==3) return true;
        bool h1 = true, h2 = true, h3 = true;
        for (int i = 4; i <= n; ++i) {
            if (h1 && h2 && h3) {
                h1=h2;
                h2=h3;
                h3= false;
            } else{
                h1=h2;
                h2=h3;
                h3= true;
            }
        }
        return h3;
    }
};

#endif //HOT100_292_H
