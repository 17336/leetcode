//
// Created by 17336 on 2022/3/28.
//

#ifndef HOT100_56_H
#define HOT100_56_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res{intervals[0]};
        for (const auto &item: intervals) {
            auto &p=res.back();
            if(res.empty()||item[0]>p[1]) res.push_back(item);
            else{
                p[1]= max(p[1],item[1]);
            }
        }
        return res;
    }
};

#endif //HOT100_56_H
