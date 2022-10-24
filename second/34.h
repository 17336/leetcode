//
// Created by 17336 on 2022/4/7.
//

#ifndef HOT100_34_H
#define HOT100_34_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> res;
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                if (mid == 0 || nums[mid - 1] != target) {
                    res.push_back(mid);
                    break;
                }
                r=mid-1;
            } else if(nums[mid]>target) r=mid-1;
            else l=mid+1;
        }
        l=0,r=nums.size()-1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                if (mid == nums.size()-1 || nums[mid + 1] != target) {
                    res.push_back(mid);
                    return res;
                }
                l=mid+1;
            } else if(nums[mid]>target) r=mid-1;
            else l=mid+1;
        }
        return {-1,-1};
    }
};

#endif //HOT100_34_H
