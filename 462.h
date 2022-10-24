//
// Created by 17336 on 2022/5/20.
//

#ifndef HOT100_462_H
#define HOT100_462_H

#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int> &nums) {
        int res = 0, x = findK(nums, nums.size() / 2);
        for (const auto &item: nums) {
            res += abs(item - x);
        }
        return res;
    }

    int findK(vector<int> &nums, int k) {
        int res = -1, l = 0, r = nums.size() - 1;
        while (res != k) {
            res = partition(nums, l, r);
            if (res > k) r = res - 1;
            if (res < k) l = res + 1;
        }
        return nums[res];
    }

    int partition(vector<int> &nums, int l, int r) {
        //随机选取一个元素作为枢轴
        int i = rand() % (r - l + 1) + l;
        swap(nums[i], nums[r]);
        int pilot = nums[l];

        while (l < r) {
            while (l < r && nums[r] >= pilot) --r;
            nums[l] = nums[r];
            while (l < r && nums[l] <= pilot) ++l;
            nums[r] = nums[l];
        }
        nums[l] = pilot;
        return l;
    }
};

#endif //HOT100_462_H
