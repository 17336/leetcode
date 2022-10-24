//
// Created by 17336 on 2022/5/10.
//

#ifndef HOT100_611_H
#define HOT100_611_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int> &nums) {
        int res = 0, len = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 2; ++i) {
            for (int j = i + 1; j < len - 1; ++j) {
                int left = j + 1, right = len - 1, tar = j, twosum = nums[i] + nums[j];
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (twosum>nums[mid]){
                        left=mid+1;
                        tar=mid;
                    } else right=mid-1;
                }
                res+=tar-j;
            }
        }
        return res;
    }
};

#endif //HOT100_611_H
