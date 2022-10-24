//
// Created by 17336 on 2021/12/2.
//

#ifndef HOT100_239_H
#define HOT100_239_H

#include "vector"
#include "set"
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int,greater<int>> memo(nums.begin(),nums.begin()+k);
        vector<int> res;
        res.push_back(*memo.begin());
        for (int i = k; i < nums.size(); ++i) {
            memo.erase(memo.find(nums[i-k]));
            memo.insert(nums[i]);
            res.push_back(*memo.begin());
        }
        return res;
    }
};

#endif //HOT100_239_H
