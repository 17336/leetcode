//
// Created by 17336 on 2021/11/1.
//

#ifndef HOT100_575_H
#define HOT100_575_H

#endif //HOT100_575_H

#include "vector"
#include "unordered_set"
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int> &candyType) {
        unordered_set<int> diff_count;
        for (const auto &candy: candyType) {
            if(!diff_count.count(candy)) diff_count.insert(candy);
            if(diff_count.size()>=candyType.size()/2) return candyType.size()/2;
        }
        return diff_count.size();
    }
};