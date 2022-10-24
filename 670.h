//
// Created by 17336 on 2022/5/14.
//

#ifndef HOT100_670_H
#define HOT100_670_H

#include <vector>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        vector<int> n(9, 0);
        int i = 0, temp = num;
        while (num) {
            n[i++] = num % 10;
            num /= 10;
        }

        //m维护从低位到高位中最大的位
        int m = 0, k = -1, d = -1;
        for (int j = 0; j < i; ++j) {
            if (n[j] > n[m]) m = j;
            else if (n[j] < n[m]) {
                d = m;
                k = j;
            }
        }
        if (k == -1) return temp;
        swap(n[d], n[k]);

        int res = 0, mask = 1;
        for (int j = 0; j < i; ++j) {
            res += n[j] * mask;
            mask *= 10;
        }
        return res;
    }
};

#endif //HOT100_670_H
