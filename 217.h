//
// Created by 17336 on 2022/4/3.
//

#ifndef HOT100_217_H
#define HOT100_217_H

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> set;
        for (const auto &item: nums) {
            if(set.count(item)) return true;
            set.insert(item);
        }
        return false;
    }
};

#endif //HOT100_217_H
