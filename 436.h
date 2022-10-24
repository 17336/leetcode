//
// Created by 17336 on 2022/5/20.
//

#ifndef HOT100_436_H
#define HOT100_436_H

#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals) {
        auto less = [](const vector<int> &a, const vector<int> &b) {
            return b[0] >= a[1];
        };
        int len = intervals.size();
        for (int i = 0; i < len; ++i) {
            intervals[i].push_back(i);
        }
        sort(intervals.begin(), intervals.end(), less);
        stack<int> s;
        vector<int> res(len, -1);
        for (int i = 0; i < len; ++i) {
            while (!s.empty() && less(intervals[s.top()], intervals[i])) {
                res[intervals[s.top()][2]] = intervals[i][2];
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};

#endif //HOT100_436_H
