//
// Created by 17336 on 2022/1/12.
//

#ifndef HOT100_334_H
#define HOT100_334_H

#include "vector"
#include "unordered_map"
#include "stack"
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        unordered_map<int,vector<int>> map;
        vector<int> s;
        int len=nums.size();
        for (int i = 0; i < len; ++i) {
            if(s.empty()||nums[i]<=nums[s.back()]){
                s.push_back(i);
                continue;
            }
            int j=s.size()-1;
            while (j>=0&&nums[i]>nums[s[j]]){
                if(map.count(s[j])&&nums[i]<=nums[map[s[j]][0]]) map[s[j]][0]=i;
                else{
                    map[s[j]].push_back(i);
                    if(map[s[j]].size()==2) return true;
                }
                --j;
            }
        }
        return false;
    }
};

#endif //HOT100_334_H
