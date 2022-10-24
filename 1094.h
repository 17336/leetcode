//
// Created by 17336 on 2022/4/7.
//

#ifndef HOT100_1094_H
#define HOT100_1094_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>> &trips, int capacity) {
        vector<int> sections(1001, 0);
        for (const auto &item: trips) {
            for (int i = item[1]+1; i <= item[2]; ++i) {
                sections[i]+=item[0];
                if(sections[i]>capacity) return false;
            }
        }
        return true;
    }
};

#endif //HOT100_1094_H
