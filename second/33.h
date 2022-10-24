//
// Created by 17336 on 2022/3/25.
//

#ifndef HOT100_33_H
#define HOT100_33_H

#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        return searchBwt(nums,target,0,nums.size()-1);
    }

    int searchBwt(vector<int> &nums, int target, int l, int r) {
        if(l==r) return nums[l]==target?l:-1;
        //l1,r1为有序区间；l2,r2为无序区间
        int mid = (l + r) / 2, l1, r1, l2, r2;
        if (nums[l] < nums[mid]) {
            l1 = l;
            r1 = mid;
            l2 = mid + 1;
            r2 = r;
        } else {
            l1=mid+1;
            r1=r;
            l2=l;
            r2=mid;
        }
        //正常二分搜索有序部分
        while (l1 <= r1) {
            int m = (l1 + r1) / 2;
            if (nums[m] == target) return m;
            else if (nums[m] > target) r1 = m - 1;
            else l1 = m + 1;
        }
        //无序部分递归
        return searchBwt(nums,target,l2,r2);
    }
};

#endif //HOT100_33_H
