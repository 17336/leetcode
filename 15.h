//
// Created by 17336 on 2021/11/2.
//

#ifndef HOT100_15_H
#define HOT100_15_H

#endif //HOT100_15_H

#include "vector"
#include "unordered_map"
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        if(nums.size()<3) return res;
        unordered_map<int,int> map;
        for (int i = 1; i < nums.size()-1; ++i) {
            map[nums[i]]++;
        }
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size()-1;
        while (r-l>1&&((nums[r]^nums[l]<0)||(nums[r]|nums[l]==0))){
            int p,sum=nums[r]+nums[l];
            if(sum>=0&&sum+nums[l+1]>0){
                r--;
                continue;
            }
            else if(sum<=0&&sum+nums[r-1]<0){
                l++;
                continue;
            }
            else {

            }
        }
    }
};