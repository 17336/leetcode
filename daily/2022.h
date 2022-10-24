//
// Created by 17336 on 2022/1/1.
//

#ifndef HOT100_2022_H
#define HOT100_2022_H

#include "vector"

using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n) {
        vector<vector<int>> res;
        if (original.size()%n!=0||original.size()/n!=m) return res;
        for (int i = 0; i < m; ++i) {
            res.emplace_back();
            int temp=i*n;
            for (int j = 0; j < n; ++j) {
                res[i].push_back(original[temp+j]);
            }
        }
        return res;
     }
};

#endif //HOT100_2022_H
