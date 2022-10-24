//
// Created by 17336 on 2022/4/22.
//

#ifndef HOT100_295_H
#define HOT100_295_H

#include <map>
#include <vector>

using namespace std;

class MedianFinder {
    int length = 0;
    map<int, int> m;
    vector<int> nums;
public:
    MedianFinder() {
        nums.resize(101, 0);
    }

    void addNum(int num) {
        if (num <= 100) ++nums[num];
        else ++m[num];
        ++length;
    }

    double findMedian() {
        int tar = (length % 2 ? length / 2 : length / 2 - 1), cur = -1, mid = 0;
        int i = 0;
        for (; i < 101; ++i) {
            cur += nums[i];
            if (cur >= tar) {
                mid += i;
                break;
            }
        }
        if (length % 2 || cur > tar) return mid;
        ++tar;
        ++i;
        for (; i < 101; ++i) {
            cur += nums[i];
            if (cur >= tar) {
                mid += i;
                return mid / 2.0;
            }
        }
        for (const auto &item: m) {
            cur += item.second;
            if (cur >= tar) return (mid + item.first) / 2.0;
        }
        return -1;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

#endif //HOT100_295_H
