//
// Created by 17336 on 2022/4/15.
//

#ifndef HOT100_47_H
#define HOT100_47_H

#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> res;
    vector<int> counts;
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        counts.resize(21,0);
        for (const auto &num: nums) {
            ++counts[num+10];
        }
        vector<int> path;
        backtrack(path);
        return res;
    }

    void backtrack(vector<int> &path){
        bool flag= true;
        for (int i = 0; i < counts.size(); ++i) {
            if(counts[i]>0){
                flag= false;
                path.push_back(i-10);
                --counts[i];
                backtrack(path);
                ++counts[i];
                path.pop_back();
            }
        }
        if(flag) res.push_back(path);
    }
};

#endif //HOT100_47_H
