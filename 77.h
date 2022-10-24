//
// Created by 17336 on 2022/3/16.
//

#ifndef HOT100_77_H
#define HOT100_77_H

#include <vector>
#include <set>

using namespace std;

class Solution {
    vector<vector<int>> res;
    int nn;
public:
    vector<vector<int>> combine(int n, int k) {
        nn = n;
        vector<int> path;
        backtrack(path, k);
        return res;
    }

    void backtrack(vector<int> &path, int k) {
        if (k == 0) {
            res.push_back(path);
            return;
        }
        int back = 1;
        if (!path.empty()) back = path.back() + 1;
        if (nn - back + 1 < k) return;
        for (int i = back; i <= nn; ++i) {
            path.push_back(i);
            backtrack(path, k - 1);
            path.pop_back();
        }
    }
};

#endif //HOT100_77_H
