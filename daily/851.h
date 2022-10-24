//
// Created by 17336 on 2021/12/15.
//

#ifndef HOT100_851_H
#define HOT100_851_H

#include "vector"

using namespace std;

class Solution {
    vector<vector<int>> all_richer;
    vector<int> res;
public:
    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet) {
        int n = quiet.size();
        all_richer.resize(n);
        res.resize(n,-1);
        for (const auto &item: richer) {
            all_richer[item[1]].push_back(item[0]);
        }
        for (int i = 0; i < n; ++i) {
            func(quiet,i);
        }
        return res;
    }

    int func(vector<int> &quiet,int i) {
        if(res[i]!=-1) return res[i];
        int who=i,q=quiet[i];
        for (const auto &item: all_richer[i]) {
            int temp=func(quiet,item);
            if(quiet[temp]<q) {
                who= temp;
                q=quiet[temp];
            }
        }
        return res[i]=who;
    }
};

#endif //HOT100_851_H
