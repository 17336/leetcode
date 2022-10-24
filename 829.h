//
// Created by 17336 on 2022/6/3.
//

#ifndef HOT100_829_H
#define HOT100_829_H

#include "basi.h"

class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int res = 1,last=INT_MAX;
        for (int i = 1; i < n; ++i) {
            int left = i, right = n - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                long sum = (i*1l + mid) * (mid - i + 1) / 2;
                if (sum > n) right = mid - 1;
                else if (sum < n) left=mid+1;
                else {
                    ++res;
                    break;
                }
            }
        }
        return res;
    }
};

#endif //HOT100_829_H
