//
// Created by 17336 on 2022/5/24.
//

#ifndef HOT100_210_H
#define HOT100_210_H

#include <basi.h>

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> edges(numCourses);
        vector<int> pres(numCourses);
        for (const auto &prerequisite: prerequisites) {
            ++pres[prerequisite[0]];
            edges[prerequisite[1]].push_back(prerequisite[0]);
        }
        vector<int> preZeros;
        for (int i = 0; i < numCourses; ++i) {
            if (pres[i] == 0) preZeros.push_back(i);
        }
        vector<int> res;
        while (!preZeros.empty()) {
            int item=preZeros.back();
            preZeros.pop_back();
            res.push_back(item);
            for (const auto &item1: edges[item]) {
                --pres[item1];
                if (pres[item1] == 0) preZeros.push_back(item1);
            }
        }
        if(res.size()!=numCourses) return {};
        return res;
    }
};

#endif //HOT100_210_H
