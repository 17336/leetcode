//
// Created by 17336 on 2022/4/17.
//

#ifndef HOT100_135_H
#define HOT100_135_H

#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        int res = 1, large = 0, last = 1;
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) {
                res += ++last;
                large = 0;
            } else if (ratings[i] == ratings[i - 1]) {
                last = 1;
                res += last;
                large = 0;
            } else {
                ++large;
                if (last == 1) res += large;
                last = 1;
                res += last;
            }
        }
        return res;
    }
};

#endif //HOT100_135_H
