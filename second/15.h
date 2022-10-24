//
// Created by 17336 on 2022/3/24.
//

#ifndef HOT100_15_H
#define HOT100_15_H

#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int len=nums.size();
        for (int i = 0; i < len&&nums[i]<=0; ++i) {
            if(i>0&&nums[i]==nums[i-1]) continue;
            int l=i+1,r=len-1;
            while (l<r){
                if(nums[l]+nums[r]+nums[i]==0) {
                    res.push_back({nums[l],nums[r],nums[i]});
                    ++l;
                    while (l<r&&nums[l]==nums[l-1]) ++l;
                    --r;
                } else if(nums[l]+nums[r]+nums[i]<0) ++l;
                else --r;
            }
        }
        return res;
    }
};

#endif //HOT100_15_H
