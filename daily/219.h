//
// Created by 17336 on 2022/1/19.
//

#ifndef HOT100_219_H
#define HOT100_219_H

#include "vector"
#include "unordered_map"

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        //记录遍历当前节点i右边k个元素（包括i）
        unordered_map<int, int> map;
        for (int i = 0; i <= k && i < nums.size(); ++i) {
            ++map[nums[i]];
            if (map[nums[i]] > 1) return true;
        }
        if (k >= nums.size() - 1) return false;
        for (int i = 1; i + k < nums.size(); ++i) {
            --map[nums[i-1]];
            ++map[nums[i+k]];
            if(map[nums[i+k]]>1) return true;
        }
        return false;
    }
};

#endif //HOT100_219_H
