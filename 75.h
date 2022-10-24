//
// Created by 17336 on 2021/11/9.
//

#ifndef HOT100_75_H
#define HOT100_75_H

#endif //HOT100_75_H

#include "vector"

using namespace std;

class Solution {
public:
    void sortColors(vector<int> &nums) {
        int count[3]={0};
        for (const auto &item: nums) {
            count[item]++;
        }
        nums.clear();
        nums.insert(nums.end(),count[0],0);
        nums.insert(nums.end(),count[1],1);
        nums.insert(nums.end(),count[2],2);
    }
};