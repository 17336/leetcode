//
// Created by 17336 on 2022/3/29.
//

#ifndef HOT100_470_H
#define HOT100_470_H

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        while (true){
            int r1=rand7(),r2=rand7();
            if((r1%2==0&&r2>3)||r1==7) continue;
            if(r1%2) return r2;
            return r2+7;
        }
        return -1;
    }
};

#endif //HOT100_470_H
