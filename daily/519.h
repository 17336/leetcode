//
// Created by 17336 on 2021/11/27.
//

#ifndef HOT100_519_H
#define HOT100_519_H

#include "cstdlib"
#include "vector"
#include "list"
using namespace std;

class Solution {
//    vector<vector<int>> vec;
    list<pair<int,int>> zero,del;
public:
    Solution(int m, int n) {
        for (int i = 0; i < m; ++i) {
//            vec.push_back({});
            for (int j = 0; j < n; ++j) {
//                vec.back().push_back(0);
                zero.emplace_back(i,j);
            }
        }
    }

    vector<int> flip() {
        del.push_back(zero.front());
        zero.erase(zero.begin());
        return {del.back().first,del.back().second};
    }

    void reset() {
        zero.splice(zero.end(),del);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */

#endif //HOT100_519_H
