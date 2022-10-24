//
// Created by 17336 on 2022/2/24.
//

#ifndef HOT100_33_H
#define HOT100_33_H

#include "vector"

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int k = -1, l = 0, n = nums.size(), r = n - 1;
        //先找到翻转数组的转折点k
        if (nums[r] < nums[l])
            while (l <= r) {
                int mid = (l + r) / 2;
                if (nums[mid + 1] < nums[mid]) {
                    k = mid;
                    break;
                } else if (nums[mid] < nums[0]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        //找到转折点后：k+1,k+2......n-1,0,1,2......k为全局升序数组
        l = k + 1;
        if (k == -1) {
            r = n - 1;
        } else r = k;
        //对数组下标:k+1,k+2......n-1,0,1,2......k代表的数据进行二分搜索
        while (l !=r) {
            int mid;
            if (l > r) {
                mid = (r + n - l) / 2;
                if (mid > n - 1 - l) mid -= n - l;
                else mid += l;
            } else mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) {
                l = (l + 1) % n;
            } else r = (r + n - 1) % n;
        }
        if(nums[r]==target) return r;
        return -1;
    }
};

#endif //HOT100_33_H
