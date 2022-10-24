//
// Created by 17336 on 2022/3/18.
//

#ifndef HOT100_7_H
#define HOT100_7_H

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x ) {
            if(res<=(INT_MAX)/10&&res>=(INT_MIN)/10) res = res*10+ x % 10;
            else return 0;
            x /= 10;
        }
        return res;
    }
};

#endif //HOT100_7_H
