//
// Created by 17336 on 2021/11/20.
//

#ifndef HOT100_594_H
#define HOT100_594_H

#endif //HOT100_594_H

#include "vector"
#include "unordered_map"

using namespace std;

class Solution {
public:
    int findLHS(vector<int> &nums) {
        int mLen = 0;
        unordered_map<int, int> map;
        for (const auto &item: nums) {
            int now = ++map[item];
            int p = map[item - 1], q = map[item + 1];
            if (p || q)
                mLen = max(mLen, now + max(p, q));
        }
        return mLen;
    }
};