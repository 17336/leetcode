//
// Created by 17336 on 2022/4/3.
//

#ifndef HOT100_231_H
#define HOT100_231_H

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        return !(~(n&(-n))&n);
    }
};

#endif //HOT100_231_H
