//
// Created by 17336 on 2022/2/25.
//

#ifndef HOT100_56_H
#define HOT100_56_H

#include <vector>
#include <algorithm>

using namespace std;

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) -> bool {
            if (a[0] < b[0] || (a[0] == b[0] && a[1] < b[1])) return true;
            return false;
        });
        vector<vector<int>> res{intervals[0]};
        for (const auto &interval: intervals) {
            if(interval[0]==res.back()[0]) res.back()[1]=interval[1];
            else if(interval[0]<=res.back()[1]&&interval[1]>res.back()[1]) res.back()[1]=interval[1];
            else if(interval[0]>res.back()[1]) res.emplace_back(interval);
        }
        return res;
    }
};

#endif //HOT100_56_H
