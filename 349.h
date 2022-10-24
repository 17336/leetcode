//
// Created by 17336 on 2022/4/27.
//

#ifndef HOT100_349_H
#define HOT100_349_H

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums2.begin(),nums2.end());
        vector<int> res;
        for (const auto &item: nums1) {
            if(s.count(item)){
                res.push_back(item);
                s.erase(item);
            }
        }
        return res;
    }
};

#endif //HOT100_349_H
