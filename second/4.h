//
// Created by 17336 on 2022/3/29.
//

#ifndef HOT100_4_H
#define HOT100_4_H

#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        if ((len1 + len2) % 2)
            return findK(nums1, nums2, 0, len1 - 1, 0, len2 - 1, (len1 + len2) / 2);
        return (findK(nums1, nums2, 0, len1 - 1, 0, len2 - 1, (len1 + len2) / 2 - 1) +
               findK(nums1, nums2, 0, len1 - 1, 0, len2 - 1, (len1 + len2) / 2))/2;
    }

    double findK(vector<int> &nums1, vector<int> &nums2, int l1, int r1, int l2, int r2, int k) {
        if (l1 > r1) return nums2[l2 + k];
        if (l2 > r2) return nums1[l1 + k];
        if (k == 0) return min(nums1[l1], nums2[l2]);
        int i = min(l1 + k / 2, r1), j = min(l2 + k / 2 , r2);
        if (nums1[i] == nums2[j]) return nums1[i];
        if (nums1[i] < nums2[j]) return findK(nums1, nums2, i + 1, r1, l2, r2, k - i - 1);
        return findK(nums1, nums2, l1, r1, j + 1, r2, k - j - 1);
    }
};

#endif //HOT100_4_H
