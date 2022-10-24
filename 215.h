//
// Created by 17336 on 2022/3/9.
//

#ifndef HOT100_215_H
#define HOT100_215_H

#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int target = nums.size() - k, l = 0, r = nums.size() - 1, mid;
        while ((mid = partition(nums, l, r)) != target) {
            if (mid < target) {
                l = mid + 1;
            } else r = mid - 1;
        }
        return nums[mid];
    }

    int partition(vector<int> &nums, int l, int r) {
        int pilot = nums[l];
        while (l < r) {
            while (l < r && nums[r] >= pilot) --r;
            nums[l] = nums[r];
            while (l < r && nums[l] <= pilot) ++l;
            nums[r] = nums[l];
        }
        nums[r] = pilot;
        return r;
    }
};

#endif //HOT100_215_H
