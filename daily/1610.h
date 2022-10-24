//
// Created by 17336 on 2021/12/16.
//

#ifndef HOT100_1610_H
#define HOT100_1610_H

#include "vector"
#include "cmath"
#include "algorithm"
using namespace std;

struct my

class Solution {
public:
    int visiblePoints(vector<vector<int>> &points, int angle, vector<int> &location) {
        vector<pair<bool, double>> slops;
        for (auto &point: points) {
            slops.push_back({point[0] > location[0], (double) (point[1] - location[1]) / (point[0] - location[0])});
        }
        sort()
    }
};

#endif //HOT100_1610_H
