//
// Created by 17336 on 2022/3/17.
//

#ifndef HOT100_875_H
#define HOT100_875_H

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
    int sum = 0;
public:
    int minEatingSpeed(vector<int> &piles, int h) {
        //向上取整
        int k = 1, r = *max_element(piles.begin(), piles.end()), mid,res;
        while (k <= r) {
            mid = (k + r) / 2;
            if (possible(piles, h, mid)) {
                r = mid - 1;
                res=mid;
            } else {
                k = mid + 1;
            }
        }
        return res;
    }

    bool possible(vector<int> &piles, int h, int k) {
        int sum = 0;
        for (const auto &item: piles) {
            sum += (item - 1) / k + 1;
        }
        return sum <= h;
    }

    void qSort(vector<int> &piles, int l, int r) {
        if (l < r) {
            int mid = parti(piles, l, r);
            qSort(piles, l, mid - 1);
            qSort(piles, mid + 1, r);
        }
    }

    int parti(vector<int> &piles, int l, int r) {
        int pilot = piles[l];
        while (l < r) {
            while (l < r && piles[r] >= pilot) --r;
            piles[l] = piles[r];
            while (l < r && piles[l] <= pilot) ++l;
            piles[r] = piles[l];
        }
        piles[l] = pilot;
        return l;
    }
};

#endif //HOT100_875_H
