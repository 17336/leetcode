//
// Created by 17336 on 2022/5/4.
//

#ifndef HOT100_1823_H
#define HOT100_1823_H

class Solution {
public:
    int findTheWinner(int n, int k) {
        int res = 0;
        for (int i = 1; i < n; ++i) {
            res = (res + k) % (i+1);
        }
        return res+1;
    }
};

#endif //HOT100_1823_H
