//
// Created by 17336 on 2021/10/30.
//

#ifndef HOT100_260_H
#define HOT100_260_H

#endif //HOT100_260_H

#include "vector"
#include "unordered_set"

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
        unordered_set<int> res;
        for (const auto &item: nums) {
            if(res.count(item)==0) res.insert(item);
            else res.erase(item);
        }
        vector<int> t;
        for (const auto &item: res) {
            t.push_back(item);
        }
        return t;
    }
};