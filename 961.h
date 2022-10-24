//
// Created by 17336 on 2022/5/21.
//

#ifndef HOT100_961_H
#define HOT100_961_H

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int> &nums) {
        unordered_set<int> s;
        for (const auto &item: nums) {
            if(s.count(item)) return item;
            s.insert(item);
        }
        return -1;
    }
};

#endif //HOT100_961_H
