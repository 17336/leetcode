//
// Created by 17336 on 2022/5/15.
//

#ifndef HOT100_812_H
#define HOT100_812_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>> &points) {
        double area = 0;
        int len = points.size();
        for (int i = 0; i < len - 2; ++i) {
            for (int j = i + 1; j < len - 1; ++j) {
                for (int k = j + 1; k < len; ++k) {
                    area = max(area, 1.0 / 2 * abs(points[i][0] * points[j][1] + points[j][0] * points[k][1] +
                                              points[k][0] * points[i][1] - points[i][0] * points[k][1] -
                                              points[j][0] * points[i][1] - points[k][0] * points[j][1]));
                }
            }
        }
        return area;
    }
};

#endif //HOT100_812_H
