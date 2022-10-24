//
// Created by 17336 on 2022/6/1.
//

#ifndef HOT100_473_H
#define HOT100_473_H

#include <basi.h>

class Solution {
public:
    bool makesquare(vector<int> &matchsticks) {
        int total = 0;
        for (const auto &item: matchsticks) {
            total += item;
        }
        if (total % 4) return false;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        int edge = total / 4, begin = 0, len = matchsticks.size();
        while (begin < len) {
            if (matchsticks[begin] > edge) return false;
            if (matchsticks[begin] == edge) {
                ++begin;
            } else break;
        }
    }

    bool dfs(int begin,) {

    }
};

#endif //HOT100_473_H
