//
// Created by 17336 on 2022/3/25.
//

#ifndef HOT100_33ADV_H
#define HOT100_33ADV_H

#include <vector>

using namespace std;


class Solution {
public:
    int search(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            //如果左半部分有序且target在有序范围内，则在左半部分搜索，否则在右半部分
            else if (nums[l] <= nums[mid]) {
                if (target < nums[mid] && target >= nums[l])
                    r = mid - 1;
                else l=mid+1;
            }
            //同理，右半部分有序时一样
            else{
                if(target<=nums[r]&&target>nums[mid]) l=mid+1;
                else r=mid-1;
            }
        }
        return -1;
    }
};

#endif //HOT100_33ADV_H
