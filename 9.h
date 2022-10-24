//
// Created by 17336 on 2022/3/18.
//

#ifndef HOT100_9_H
#define HOT100_9_H

#include <stack>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int  reverse = 0;
        int t = x;
        while (t) {
            try {
                reverse = reverse * 10 + t % 10;
            }
            catch (...) {
                return false;
            }
            t /= 10;
        }
        return reverse == x;
    }
};

#endif //HOT100_9_H
