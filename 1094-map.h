//
// Created by 17336 on 2022/4/7.
//

#ifndef HOT100_1094_MAP_H
#define HOT100_1094_MAP_H

#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>> &trips, int capacity) {
        map<int,int> m;
        for (const auto &trip: trips) {
            m[trips[1]]+=trip[0];
            m[trips[2]]-=trip[0];
        }

        int people=0;
        for (const auto &item: m) {
            people+=item.second;
            if(people>capacity) return false;
        }
        return true;
    }
};

#endif //HOT100_1094_MAP_H
