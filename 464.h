//
// Created by 17336 on 2022/5/22.
//

#ifndef HOT100_464_H
#define HOT100_464_H

#include <vector>

using namespace std;

class Solution {
    unsigned choose = 0;
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) return false;
        if (desiredTotal <= 0) return true;
        for (int i = maxChoosableInteger; i >= 1; --i) {
            //如果可以选i
            if ((choose & (1 << i)) == 0) {
                if (i >= desiredTotal) return true;
                //某位置一
                choose |= 1 << i;
                //如果对手必败，则必胜
                if (!canIWin(maxChoosableInteger, desiredTotal - i)) return true;
                //某位置零
                choose &= !(1 << i);
            }
        }
        return false;
    }
};

#endif //HOT100_464_H
