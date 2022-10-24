//
// Created by 17336 on 2021/11/17.
//

#ifndef HOT100_448_H
#define HOT100_448_H

#endif //HOT100_448_H

#include "vector"
#include "unordered_set"
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        unordered_set<int> memo(nums.begin(),nums.end());
        for (int i = 1; i <= nums.size(); ++i) {
            if(!memo.count(i)) res.push_back(i);
        }
        return res;
    }
};