//
// Created by 17336 on 2021/11/17.
//

#ifndef HOT100_448BEST_H
#define HOT100_448BEST_H

#endif //HOT100_448BEST_H

#include "vector"
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int n=nums.size();
        for (int i = 0; i < n; ++i) {
            //nums中nums[i]
            nums[(nums[i]-1)%n]+=n;
        }
        for (int i = 0; i < n; ++i) {
            if(nums[i]<=n) res.push_back(i+1);
        }
        return res;
    }
};